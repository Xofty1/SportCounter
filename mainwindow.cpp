#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    groupCount = 1;
    participants = new vector<vector<Participant>>();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_answer_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Выберите файл Excel"), "", tr("Файлы Excel (*.xlsx *.xls)"));
    groups = read_groups();
    read_data(filePath, groups);
    processing_data(*participants);
    write_data(*participants);



}


void MainWindow::on_pushButton_add_group_clicked()
{
    groupCount ++;
    // Создаем два новых QLineEdit
    QLineEdit *lineEdit1 = new QLineEdit(this);
    QLineEdit *lineEdit2 = new QLineEdit(this);

    // Получаем текущее количество строк в сетке
    groupCount = ui->gridLayout_groups->rowCount();

    // Добавляем их в gridLayout вашего окна
    ui->gridLayout_groups->addWidget(lineEdit1, groupCount, 0); // Добавляем в столбец 0
    ui->gridLayout_groups->addWidget(lineEdit2, groupCount, 1); // Добавляем в столбец 1

    // Делаем их видимыми
    lineEdit1->setVisible(true);
    lineEdit2->setVisible(true);
}

void MainWindow::on_pushButton_delete_group_clicked()
{

    if (groupCount == 0) // Проверяем, есть ли что удалять
        return;

    // Получаем элементы ячеек текущей строки
    QLayoutItem *item1 = ui->gridLayout_groups->itemAtPosition(groupCount, 0);
    QLayoutItem *item2 = ui->gridLayout_groups->itemAtPosition(groupCount, 1);

    // Проверяем, есть ли элементы в ячейках
    if (item1 && item2) {
        // Удаляем элементы из сетки
        ui->gridLayout_groups->removeItem(item1);
        ui->gridLayout_groups->removeItem(item2);

        // Удаляем элементы из памяти
        delete item1->widget();
        delete item2->widget();

        // Освобождаем память, выделенную под QLayoutItem
        delete item1;
        delete item2;
    }

    // Уменьшаем rowCount для перехода к предыдущей строке
    groupCount--;


    // Перерисовываем сетку
    ui->gridLayout_groups->invalidate();
}

void MainWindow::read_data(QString filePath, vector<double>* groups){
    int emptyRow = -1;
    if (!filePath.isEmpty()) {
        QXlsx::Document xlsx(filePath);
        if (!xlsx.load()) {
            QMessageBox::warning(this, "Ошибка", "Невозможно считать данные");
        }
        else{
            qDebug() << "Count Columns " << xlsx.dimension().columnCount();
            for (int row = 2; row <= xlsx.dimension().rowCount(); ++row) {
                QString name = xlsx.read(row, 2).toString();
                QVariant yearVariant = xlsx.read(row, 3);
                QVariant teamVariant = xlsx.read(row, 4);
                // Проверка, что все значения не пустые и не нулевые
                if (!name.isEmpty() && yearVariant.isValid() && !yearVariant.isNull() && teamVariant.isValid() && !teamVariant.isNull()) {
                    int year = yearVariant.toInt();
                    int number_of_team = teamVariant.toInt();
                    vector<double> * scores = new vector<double>();
                    int *emptyCell = new int [2];
                    emptyCell[0] = -1;
                    for (int col = 5; col <= xlsx.dimension().columnCount();++col){
                        QVariant scoreVariant = xlsx.read(row, col);
                        if (scoreVariant.isValid() && !scoreVariant.isNull())
                            scores->push_back(scoreVariant.toDouble());
                        else{
                            emptyCell[1] = row;
                            emptyCell[0] = col;
                            break;
                        }
                    }
                    if (emptyCell[0] != -1)
                    {
                        QChar columnLetter = 'A' + emptyCell[0]-1;

                        // Преобразуем номер строки (индекс) в число
                        QString cellPosition = QString("%1%2").arg(columnLetter).arg(emptyCell[1] + 1);

                        // Формируем сообщение с предупреждением
                        QString message = QString("Проверьте содержимое клетки %1").arg(cellPosition);

                        // Отображаем предупреждающее сообщение
                        QMessageBox::warning(this, "Ошибка", message);
                        continue;
                    }
                    bool added = false;
                    for (size_t i = 0; i+1 <= groups->size();i+=2){
                        if (year >= groups->at(i) and year <= groups->at(i+1))
                        {
                            while (participants->size() <= i / 2) {
                                participants->emplace_back();
                            }
                            Participant newParticipant(name, number_of_team, year,*scores);
                            (*participants)[i/2].push_back(newParticipant);
                            added = true;
                            break;
                        }

                    }
                    if (!added){
                        QMessageBox::warning(this, "Ошибка", "Участник в строке " +  QString::number(row) + " не соответствует ни одной возрастной группе");
                    }

                } else {
                    emptyRow = row;
                }
            }
        }
        if (emptyRow != -1)
        {
            QMessageBox::warning(this, "Ошибка", "Данные в строке " + QString::number(emptyRow) + " имеют пустые поля");
        }
    }
}


vector<double>* MainWindow::read_groups(){
    vector<double> *groups = new vector<double>();
    for (int i = 0; i < ui->gridLayout_groups->rowCount(); ++i) {
        // Получаем элемент в ячейке (i, 0) - это первый столбец
        QLineEdit *lineEdit1 = qobject_cast<QLineEdit*>(ui->gridLayout_groups->itemAtPosition(i, 0)->widget());
        // Получаем элемент в ячейке (i, 1) - это второй столбец
        QLineEdit *lineEdit2 = qobject_cast<QLineEdit*>(ui->gridLayout_groups->itemAtPosition(i, 1)->widget());

        if (lineEdit1 && lineEdit2) {
            // Считываем текст из QLineEdit
            QString text1 = lineEdit1->text();
            QString text2 = lineEdit2->text();
            groups->push_back(text1.toDouble());
            groups->push_back(text2.toDouble());
        }
    }
    for (size_t i = 0; i < groups->size(); i++){
        qDebug() << "The value is: " << groups->at(i);
    }
    return groups;
}

void MainWindow::write_data(const std::vector<std::vector<Participant>>& participants) {
    QXlsx::Document xlsx_output;
    int forName = 0;
    for (size_t i = 0; i < participants.size(); ++i) {
        // Создаем новый лист с именем "GroupX", где X - номер группы
        QString sheetName = QString::number(groups->at(forName)) + " - " + QString::number(groups->at(forName+1));
        forName+=2;
        xlsx_output.addSheet(sheetName);
        xlsx_output.selectSheet(sheetName);

        // Записываем имена участников в лист
        for (size_t j = 0; j < participants[i].size(); ++j) {
            QString participantName = participants[i][j].getName();
            QChar columnLetter = 'A';
            xlsx_output.write(QString("A%1").arg(j + 1), participantName);  // Записываем имя в колонку A
            size_t score;
            for (score = 0; score < participants[i][j].getScores().size();++score){
                xlsx_output.write(QString("%1%2").arg(columnLetter+score + 1).arg(j + 1), participants[i][j].getScores().at(score));
            }
            xlsx_output.write(QString("%1%2").arg(columnLetter+score + 1).arg(j + 1), participants[i][j].getPlace());
            const auto& scores = participants[i][j].getScores();
                       for (size_t score = 0; score < scores.size(); ++score) {
                           // Буква столбца для результатов, начинаем с 'B' (столбец 2)
                           QChar columnLetter = QChar(((QChar)'B').unicode() + static_cast<int>(score));
                           xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + 1), scores[score]);
                       }

                       // Записываем место
                       QChar placeColumnLetter = QChar(((QChar)'B').unicode() + static_cast<int>(scores.size()));
                       xlsx_output.write(QString("%1%2").arg(placeColumnLetter).arg(j + 1), participants[i][j].getPlace());

        }
    }

    if (!xlsx_output.saveAs("output.xlsx")) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл");
    }
}


void MainWindow::processing_data(std::vector<std::vector<Participant>>& participants) {
    for (size_t i = 0; i < participants.size(); ++i) {
        // Сортируем результаты по очкам для каждого соревнования
        for (size_t competitive = 0; competitive < participants[i][0].getScores().size(); ++competitive) {
            std::sort(participants[i].begin(), participants[i].end(), [competitive](const Participant &a, const Participant &b) {
                return a.getScores().at(competitive) > b.getScores().at(competitive); // Для сортировки по убыванию результатов
            });

            // Обновляем общее количество очков участников
            for (size_t points = 0; points < participants[i].size(); ++points) {
                participants[i][points].setTotalPoints(participants[i][points].getTotalPoints() + points + 1);
            }
        }

        // Сортируем результаты по общему количеству очков
        std::sort(participants[i].begin(), participants[i].end(), [](const Participant &a, const Participant &b) {
            return a.getTotalPoints() < b.getTotalPoints(); // Для сортировки по убыванию общего количества очков
        });

        // Обновляем места участников
        for (size_t place = 0; place < participants[i].size(); ++place) {
            participants[i][place].setPlace(place + 1);
        }
    }
}

