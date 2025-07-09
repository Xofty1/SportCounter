#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    groupCount = 0;

    ui->setupUi(this);
    setAcceptDrops(true);
    createCompetition = new CreateCompetition();
    infoWindow = new InfoWindow();
    connect(createCompetition, &CreateCompetition::signalGroup, this, &MainWindow::slotGroup);
    connect(createCompetition, &CreateCompetition::signalCompetitionType, this, &MainWindow::slotCompetitionType);
    ui->pushButton_answer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

MainWindow::~MainWindow()
{
    delete ui;
    clear_data();
}

void MainWindow::on_pushButton_answer_clicked()
{
    if (groups == nullptr || groups->size() == 0){
        QMessageBox::warning(this, "Ошибка", "Выберите возрастные категории");
    }
    else{

        if (filePath.isEmpty()){
            QMessageBox::warning(this, "Ошибка", "Выберите файл с данными участников");
            return;
        }
        participants = new std::vector<std::vector<Participant>>();
        colNames = new std::vector<QString>();
        read_data(filePath, groups,colNames);
        processing_data(*participants);
        write_data(*participants);
        clear_data();
    }
}
void MainWindow::clear_data() {
    // Освобождаем память от participants
    if (participants != nullptr) {
        for (size_t i = 0; i < participants->size(); ++i) {
            (*participants)[i].clear(); // Очищаем внутренние вектора
        }
        participants->clear(); // Очищаем внешний вектор
        delete participants; // Освобождаем память, выделенную для внешнего вектора
        participants = nullptr; // Устанавливаем указатель на nullptr
    }

    // Освобождаем память от colNames
    if (colNames != nullptr) {
        colNames->clear(); // Очищаем вектор строк
        delete colNames; // Освобождаем память, выделенную для вектора строк
        colNames = nullptr; // Устанавливаем указатель на nullptr
    }
}

void MainWindow::read_data(QString filePath, vector<double>* groups, vector<QString>* colNames) {
    if (filePath.isEmpty()) {
        return;
    }

    QXlsx::Document xlsx(filePath);
    if (!xlsx.load()) {
        QMessageBox::warning(this, "Ошибка", "Невозможно считать данные");
        return;
    }

    readColumnNames(xlsx, colNames);
    readParticipants(xlsx, groups);
}

void MainWindow::readColumnNames(QXlsx::Document& xlsx, vector<QString>* colNames) {
    for (int col = 1; col <= xlsx.dimension().columnCount(); ++col) {
        colNames->push_back(xlsx.read(1, col).toString());
    }
}

void MainWindow::readParticipants(QXlsx::Document& xlsx, vector<double>* groups) {
    int emptyRow = -1;

    for (int row = 2; row <= xlsx.dimension().rowCount(); ++row) {
        QString name = xlsx.read(row, 2).toString();
        QVariant yearVariant = xlsx.read(row, 3);
        QVariant teamVariant = xlsx.read(row, 4);

        if (!name.isEmpty() && yearVariant.isValid() && !yearVariant.isNull() && teamVariant.isValid() && !teamVariant.isNull()) {
            int year = yearVariant.toInt();
            int number_of_team = teamVariant.toInt();
            vector<double> scores;

            if (competitionType == 0) {
                if (!processCompetitionType0(xlsx, row, scores)) {
                    continue;
                }
                addParticipant(groups, name, number_of_team, year, scores, row);
            } else if (competitionType == 1) {
                QTime start, end;
                int penalty_loop;

                if (!processCompetitionType1(xlsx, row, start, end, penalty_loop)) {
                    continue;
                }
                addParticipant(groups, name, number_of_team, year, start, end, penalty_loop, row);
            }
        } else {
            emptyRow = row;
        }
    }

    if (emptyRow != -1) {
        QMessageBox::warning(this, "Ошибка", "Данные в строке " + QString::number(emptyRow) + " имеют пустые поля");
    }
}

bool MainWindow::processCompetitionType0(QXlsx::Document& xlsx, int row, vector<double>& scores) {
    for (int col = 5; col <= xlsx.dimension().columnCount(); ++col) {
        QVariant scoreVariant = xlsx.read(row, col);
        if (scoreVariant.isValid() && !scoreVariant.isNull()) {
            scores.push_back(scoreVariant.toDouble());
        } else {
            QChar columnLetter = 'A' + col - 1;
            QString cellPosition = QString("%1%2").arg(columnLetter).arg(row + 1);
            QString message = QString("Проверьте содержимое клетки %1").arg(cellPosition);
            QMessageBox::warning(this, "Ошибка", message);
            return false;
        }
    }
    return true;
}

bool MainWindow::processCompetitionType1(QXlsx::Document& xlsx, int row, QTime& start, QTime& end, int& penalty_loop) {
    QXlsx::Cell* startCell = xlsx.cellAt(row, 6);
    QXlsx::Cell* endCell = xlsx.cellAt(row, 5);
    QVariant penaltyLoopVariant = xlsx.read(row, 7);

    if (penaltyLoopVariant.isValid() && !penaltyLoopVariant.isNull()) {
        penalty_loop = penaltyLoopVariant.toInt();
    } else {
        QMessageBox::warning(this, "Ошибка", "Ячейка G" + QString::number(row) + " пуста или не существует");
        return false;
    }

    if (startCell && endCell) {
        start = convertToTime(startCell);
        end = convertToTime(endCell);

        if (!start.isValid()) {
            QMessageBox::warning(this, "Ошибка", "Невалидное время в ячейке СТАРТ в ряду " + QString::number(row));
            return false;
        }
        if ( !end.isValid()) {
            QMessageBox::warning(this, "Ошибка", "Невалидное время в ячейке ФИНИШ в ряду " + QString::number(row));
            return false;
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Ячейки E или F" + QString::number(row) + " пусты или не существуют");
        return false;
    }

    return true;
}

QTime MainWindow::convertToTime(QXlsx::Cell* cell) {
    QString cellValue = cell->value().toString();
    QStringList timeParts = cellValue.split('.');

    int minutes = timeParts[0].toInt();
        int seconds = timeParts[1].toInt();
        int milliseconds = timeParts.size() > 2 ? timeParts[2].toInt() : 0;

        return QTime(0, minutes, seconds, milliseconds);
}

void MainWindow::addParticipant(vector<double>* groups, const QString& name, int number_of_team, int year, const vector<double>& scores, int row) {
    bool added = false;

    for (size_t i = 0; i + 1 <= groups->size(); i += 2) {
        if (year >= groups->at(i) && year <= groups->at(i + 1)) {
            while (participants->size() <= i / 2) {
                participants->emplace_back();
            }

            Participant newParticipant(name, number_of_team, year, scores);
            (*participants)[i / 2].push_back(newParticipant);
            added = true;
            break;
        }
    }

    if (!added) {
        QMessageBox::warning(this, "Ошибка", "Участник в строке " + QString::number(row) + " не соответствует ни одной возрастной группе");
    }
}

void MainWindow::addParticipant(vector<double>* groups, const QString& name, int number_of_team, int year, const QTime& start, const QTime& end, int penalty_loop, int row) {
    bool added = false;

    for (size_t i = 0; i + 1 <= groups->size(); i += 2) {
        if (year >= groups->at(i) && year <= groups->at(i + 1)) {
            while (participants->size() <= i / 2) {
                participants->emplace_back();
            }

            Participant newParticipant(name, number_of_team, year, start, end, QTime(0, 0).addMSecs(start.msecsTo(end)), penalty_loop);
            (*participants)[i / 2].push_back(newParticipant);
            added = true;
            break;
        }
    }

    if (!added) {
        QMessageBox::warning(this, "Ошибка", "Участник в строке " + QString::number(row) + " не соответствует ни одной возрастной группе");
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
        if (n == 5 and competitionType == 1){
            xlsx_output.write(QString("%1%2").arg(columnLetter).arg(1),"Общее время");
            columnLetter = QChar((columnLetter).unicode() + 1);
        }
    }
    if ( competitionType == 0){
        xlsx_output.write(QString("%1%2").arg(columnLetter).arg(1),"Общее место");
        columnLetter = QChar((columnLetter).unicode() + 1);
        xlsx_output.write(QString("%1%2").arg(columnLetter).arg(1),"Всего очков");
    }
    else{
        xlsx_output.write(QString("%1%2").arg(columnLetter).arg(1),"Общее место");
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
            xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift),
                (*participants)[i].at(j).getEnd().toString("mm:ss.zzz"));
            //xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), (*participants)[i].at(j).getEnd());
            columnLetter = QChar((columnLetter).unicode() + 1);
            xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift),
                (*participants)[i].at(j).getStart().toString("mm:ss.zzz"));
            //xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift), (*participants)[i].at(j).getStart());
            columnLetter = QChar((columnLetter).unicode() + 1);
            xlsx_output.write(QString("%1%2").arg(columnLetter).arg(j + shift),
                (*participants)[i].at(j).getTotalTime().toString("mm:ss.zzz"));

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
    QString xlsxFileName = QFileDialog::getSaveFileName(this, tr("Сохранить файл Excel"), "", tr("Файлы Excel (*.xlsx *.xls)"));
    if (!xlsx_output.saveAs(xlsxFileName)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл");
    }
}



bool MainWindow::areEqual(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}

void MainWindow::processing_data(std::vector<std::vector<Participant>>& participants) {
    qDebug()<<"Все ок до цикла";
    for (size_t i = 0; i < participants.size(); ++i) {
        qDebug()<<"Все ок после цикла";
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
                place = place + 1;
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
            QFileInfo fileInfo(filePath);
            QString fileName = fileInfo.fileName();
            ui->label->setText(fileName);
            ui->pushButton_file_choose->setText("Очистить");
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

void MainWindow::on_pushButton_download_olympic_games_clicked()
{
    download_example(":/examples/Пример олимпийских игр.xlsx");
}

void MainWindow::on_pushButton_download_biathlon_clicked()
{
    download_example(":/examples/Пример биатлона.xlsx");
}

void MainWindow::download_example(QString resourcePath){


    QString destinationPath = QFileDialog::getSaveFileName(this, tr("Сохранить файл Excel"), "", tr("Файлы Excel (*.xlsx *.xls)"));

    QFile file(resourcePath);
    if (file.exists()) {
        if (file.copy(destinationPath)) {
            QMessageBox::information(this, "Успешно", "Файл успешно скачан!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл.");
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Такого файла нет.");
    }
}

void MainWindow::on_pushButton_file_choose_clicked()
{
    if (filePath.isEmpty()) {
        filePath = QFileDialog::getOpenFileName(this, tr("Выберите файл Excel"), "", tr("Файлы Excel (*.xlsx *.xls)"));
        if (!filePath.isEmpty()){
            ui->pushButton_file_choose->setText("Очистить");
            QFileInfo fileInfo(filePath);
            QString fileName = fileInfo.fileName();
            ui->label->setText(fileName);
        }
    }
    else{
        filePath.clear();
        ui->pushButton_file_choose->setText("Выбрать");
        ui->label->setText("Файл");
    }
}

void MainWindow::on_pushButton_info_clicked()
{
    infoWindow->show();
}
