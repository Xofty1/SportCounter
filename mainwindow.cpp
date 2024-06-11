#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    colNames = new vector<QString>();
    groupCount = 0;
    participants = new vector<vector<Participant>>();
    ui->setupUi(this);
    setAcceptDrops(true);
    createCompetition = new CreateCompetition();
    connect(createCompetition, &CreateCompetition::signalGroup, this, &MainWindow::slotGroup);
    connect(createCompetition, &CreateCompetition::signalCompetitionType, this, &MainWindow::slotCompetitionType);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_answer_clicked()
{
    if (filePath == NULL)
        filePath = QFileDialog::getOpenFileName(this, tr("Выберите файл Excel"), "", tr("Файлы Excel (*.xlsx *.xls)"));
    read_data(filePath, groups,colNames);
    processing_data(*participants);
    write_data(*participants);
}

void MainWindow::read_data(QString filePath, vector<double>* groups,vector <QString>* colNames){
    int emptyRow = -1;
    if (!filePath.isEmpty()) {
        QXlsx::Document xlsx(filePath);
        if (!xlsx.load()) {
            QMessageBox::warning(this, "Ошибка", "Невозможно считать данные");
        }
        else{
            for (int col = 1; col <= xlsx.dimension().columnCount(); ++col){
                colNames->push_back(xlsx.read(1, col).toString());
            }
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
                    if (competitionType == 0){
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
                    }
                    else{
                        if (competitionType == 1){

                            QXlsx::Cell *startCell = xlsx.cellAt(row, 6);
                            QXlsx::Cell *endCell = xlsx.cellAt(row, 5);
                            QTime start;
                            QTime end;
                            QVariant penaltyLoopVariant = xlsx.read(row, 8);
                            int penalty_loop;
                            if (penaltyLoopVariant.isValid() && !penaltyLoopVariant.isNull()){
                                penalty_loop = penaltyLoopVariant.toInt();
                            }
                            else{
                                QMessageBox::warning(this, "Ошибка", "Ячейка G" + QString::number(row) + " пуста или не существует");
                            }
                            if (startCell) {
                                if (startCell->cellType() == QXlsx::Cell::DateType){
                                    QMessageBox::warning(this, "Ошибка", "Время " + startCell->value().toTime().toString());
                                }
                                QString cellValue = startCell->value().toString(); // Получаем значение ячейки как строку
                                QStringList timeParts = cellValue.split('.');
                                int hours = timeParts[0].toInt();
                                int minutes = timeParts[1].toInt();
                                int seconds = timeParts[2].toInt();

                                // Создаем объект QTime
                                QTime time(hours, minutes, seconds);



                                start = time; // Преобразуем строк
                                if (start.isValid()) {
                                    std::cout << "Время из ячейки: " << start.toString("hh:mm:ss").toStdString() << std::endl;
                                } else {
                                    QMessageBox::warning(this, "Ошибка", "Невалиное время в ячейке");

                                }
                            } else {
                                QMessageBox::warning(this, "Ошибка", "Ячейка E" + QString::number(row) + " пуста или не существует");
                            }
                            if (endCell) {
                                //                                end = endCell->value().toTime(); // Преобразуем строку в QTime
                                QString cellValue = endCell->value().toString(); // Получаем значение ячейки как строку
                                QStringList timeParts = cellValue.split('.');
                                int hours = timeParts[0].toInt();
                                int minutes = timeParts[1].toInt();
                                int seconds = timeParts[2].toInt();

                                // Создаем объект QTime
                                QTime time(hours, minutes, seconds);
                                end = time;
                                if (end.isValid()) {
                                    std::cout << "Время из ячейки: " << end.toString("hh:mm:ss").toStdString() << std::endl;
                                } else {
                                    QMessageBox::warning(this, "Ошибка", "Невалиное время в ячейке");

                                }
                            } else {
                                QMessageBox::warning(this, "Ошибка", "Ячейка F" + QString::number(row) + " пуста или не существует");
                            }

                            bool added = false;
                            for (size_t i = 0; i+1 <= groups->size();i+=2){
                                if (year >= groups->at(i) and year <= groups->at(i+1))
                                {
                                    while (participants->size() <= i / 2) {
                                        participants->emplace_back();
                                    }
                                    Participant newParticipant(name, number_of_team, year,start,end, QTime(0, 0).addSecs(start.secsTo(end)),penalty_loop);
                                    (*participants)[i/2].push_back(newParticipant);
                                    added = true;
                                    break;
                                }

                            }
                            if (!added){
                                QMessageBox::warning(this, "Ошибка", "Участник в строке " +  QString::number(row) + " не соответствует ни одной возрастной группе");
                            }
                        }

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

void MainWindow::write_column_names(QXlsx::Document &xlsx_output){
    QChar columnLetter = 'A';
    for (int n = 0; n < colNames->size();++n){

        xlsx_output.write(QString("%1%2").arg(columnLetter).arg(1),colNames->at(n));
        columnLetter = QChar((columnLetter).unicode() + 1);
        if (n > 3 and competitionType == 0){
            xlsx_output.write(QString("%1%2").arg(columnLetter).arg(1),"Место");
            columnLetter = QChar((columnLetter).unicode() + 1);
        }
    }
    if ( competitionType == 0){
        xlsx_output.write(QString("%1%2").arg(columnLetter).arg(1),"Общее место");
        columnLetter = QChar((columnLetter).unicode() + 1);
        xlsx_output.write(QString("%1%2").arg(columnLetter).arg(1),"Всего очков");
    }
}

void MainWindow::write_results(QXlsx::Document &xlsx_output, size_t i){
    int shift = 2;// сдвиг на самом деле на 1 меньше чем shift
    for (size_t j = 0; j < (*participants)[i].size(); ++j) {
        QString participantName = (*participants)[i].at(j).getName();
        QChar columnLetter = 'B';

        xlsx_output.write(QString("A%1").arg(j+shift),j+1);
        xlsx_output.write(QString("%1%2").arg(columnLetter ).arg(j + shift), participantName);  // Записываем имя в колонку A

        columnLetter = QChar((columnLetter).unicode() + 1);

        xlsx_output.write(QString("%1%2").arg(columnLetter ).arg(j + shift), (*participants)[i].at(j).getYear());

        columnLetter = QChar((columnLetter).unicode() + 1);

        xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), (*participants)[i].at(j).getNumberOfTeam());
        if(competitionType == 0){
            const auto& scores = (*participants)[i].at(j).getScores();
            const auto& points = (*participants)[i].at(j).getPoints();
            for (size_t score = 0; score < scores.size(); ++score) {
                // Буква столбца для результатов, начинаем с 'B' (столбец 2)
                columnLetter = QChar((columnLetter).unicode() + 1);
                xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), scores[score]);
                columnLetter = QChar((columnLetter).unicode() + 1);
                xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), points[score]);
            }
        }
        else{
            columnLetter = QChar((columnLetter).unicode() + 1);
            xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), (*participants)[i].at(j).getEnd());
            columnLetter = QChar((columnLetter).unicode() + 1);
            xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), (*participants)[i].at(j).getStart());
            columnLetter = QChar((columnLetter).unicode() + 1);
            xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), (*participants)[i].at(j).getTotalTime());
            columnLetter = QChar((columnLetter).unicode() + 1);
            xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), (*participants)[i].at(j).getPenaltyLoop());

        }

        columnLetter = QChar((columnLetter).unicode() + 1);
        xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), (*participants)[i].at(j).getPlace());
        if(competitionType == 0){
            columnLetter = QChar((columnLetter).unicode() + 1);
            xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), (*participants)[i].at(j).getTotalPoints());
        }
    }
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
        write_column_names(xlsx_output);
        qDebug() << i;
        write_results(xlsx_output, i);
    }
    if (!xlsx_output.saveAs("output.xlsx")) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл");
    }
}



bool MainWindow::areEqual(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}

void MainWindow::processing_data(std::vector<std::vector<Participant>>& participants) {

    for (size_t i = 0; i < participants.size(); ++i) {
        // Сортируем результаты по очкам для каждого соревнования
        if (competitionType == 0){
            processing_olympic_games(participants, i);
        }
        else {
            processing_biathlon(participants, i);
        }

        // Сортируем результаты по общему количеству очков
        std::sort(participants[i].begin(), participants[i].end(), [](const Participant &a, const Participant &b) {
            return a.getTotalPoints() < b.getTotalPoints(); // Для сортировки по убыванию общего количества очков
        });

        int place = 1;
        // Обновляем места участников
        for (size_t t = 0; t < participants[i].size(); ++t) {
            if (t > 0 && !areEqual(participants[i][t].getTotalPoints(), participants[i][t - 1].getTotalPoints(), 1e-4)) {
                place = t + 1;
            }
            participants[i][t].setPlace(place);
        }
    }
}

void MainWindow::processing_olympic_games(std::vector<std::vector<Participant> > &participants, int i){
    for (size_t competitive = 0; competitive < participants[i][0].getScores().size(); ++competitive) {
        if (competitive == participants[i][0].getScores().size()-1){
            std::sort(participants[i].begin(), participants[i].end(), [competitive](const Participant &a, const Participant &b) {
                return a.getScores().at(competitive) < b.getScores().at(competitive);
            });
        }
        else{
            std::sort(participants[i].begin(), participants[i].end(), [competitive](const Participant &a, const Participant &b) {
                return a.getScores().at(competitive) > b.getScores().at(competitive);
            });
        }
        int points = 1;
        // Обновляем общее количество очков участников
        for (size_t j = 0; j < participants[i].size(); ++j) {
            participants[i][j].setTotalPoints(participants[i][j].getTotalPoints() + points);
            participants[i][j].addPoints(points);
            if (j < participants[i].size() - 1 && !areEqual(participants[i][j].getScores().at(competitive), participants[i][j + 1].getScores().at(competitive), 1e-4)) {
                points++;
            }
        }
    }
}

void MainWindow::processing_biathlon(std::vector<std::vector<Participant> > &participants, int i){
    std::sort(participants[i].begin(), participants[i].end(), [](const Participant &a, const Participant &b) {
        return a.getTotalTime() < b.getTotalTime();
    });
    int points = 1;
    // Обновляем общее количество очков участников
    for (size_t j = 0; j < participants[i].size(); ++j) {
        participants[i][j].setTotalPoints(participants[i][j].getTotalPoints() + points);
        participants[i][j].addPoints(points);
        if (j < participants[i].size() - 1 && participants[i][j].getTotalTime() != participants[i][j+1].getTotalTime()) {
            points++;
        }
    }
}


void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        QList<QUrl> urlList = event->mimeData()->urls();
        if (urlList.size() == 1 && urlList[0].toLocalFile().endsWith(".xlsx")) {
            event->acceptProposedAction();
        }
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        QList<QUrl> urlList = event->mimeData()->urls();
        if (urlList.size() == 1 && urlList[0].toLocalFile().endsWith(".xlsx")) {
            filePath = urlList[0].toLocalFile();
            ui->label->setText("File dropped: " + filePath);
            // Здесь можно добавить обработку файла
        }
    }
}

void MainWindow::on_pushButton_createCompetition_clicked()
{
    createCompetition->show();
}

void MainWindow::slotGroup(vector<double> *groups)
{
    this->groups = groups;
}

void MainWindow::slotCompetitionType(int competitionType)
{
    this->competitionType = competitionType;
}
