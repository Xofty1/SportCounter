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

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_answer_clicked();

    void on_pushButton_createCompetition_clicked();

public slots:
    void slotGroup(vector<double>* groups);
    void slotCompetitionType(int competitionType);

private:
    CreateCompetition *createCompetition;
    int groupCount;
    vector<vector<Participant>> *participants;
    vector<double> *groups;
    vector <QString>* colNames;
    QString filePath;
    int competitionType = 0;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
