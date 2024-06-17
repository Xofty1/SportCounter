#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>
#include <cmath>
#include <QMimeData>
#include <QUrl>
#include <QSpinBox>

#include "data/Participant.cpp"
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#include "createcompetition.h"
#include "infowindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void read_data(QString filePath, vector<double>* groups, vector <QString>* colNames);
    void write_data(const std::vector<std::vector<Participant>>& participants);
    void processing_data( std::vector<std::vector<Participant>>& participants);
    bool areEqual(double a, double b, double epsilon);
    void write_column_names(QXlsx::Document &xlsx_output);
    void write_results(QXlsx::Document &xlsx_output, size_t i);
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void processing_olympic_games(std::vector<std::vector<Participant> > &participants, int i);
    void processing_biathlon(std::vector<std::vector<Participant> > &participants, int i);
    void clear_data();
    void download_example(QString example);
    void readColumnNames(QXlsx::Document& xlsx, vector<QString>* colNames);
    void readParticipants(QXlsx::Document& xlsx, vector<double>* groups);
    bool processCompetitionType0(QXlsx::Document& xlsx, int row, vector<double>& scores);
    bool processCompetitionType1(QXlsx::Document& xlsx, int row, QTime& start, QTime& end, int& penalty_loop);
    QTime convertToTime(QXlsx::Cell* cell);
    void addParticipant(vector<double>* groups, const QString& name, int number_of_team, int year, const vector<double>& scores, int row);
    void addParticipant(vector<double>* groups, const QString& name, int number_of_team, int year, const QTime& start, const QTime& end, int penalty_loop, int row);




    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_answer_clicked();

    void on_pushButton_createCompetition_clicked();

    void on_pushButton_download_olympic_games_clicked();

    void on_pushButton_download_biathlon_clicked();

    void on_pushButton_file_choose_clicked();

    void on_pushButton_info_clicked();

public slots:
    void slotGroup(vector<double>* groups);
    void slotCompetitionType(int competitionType);

private:
    CreateCompetition *createCompetition;
    InfoWindow *infoWindow;
    int groupCount;
    vector<vector<Participant>> *participants;
    vector<double> *groups = nullptr;
    vector <QString>* colNames;
    QString filePath;
    int competitionType = 0;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
