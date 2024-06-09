#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>

#include "data/Participant.cpp"
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int groupCount;
    vector<vector<Participant>> *participants;
    vector<double> *groups;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_answer_clicked();

    void on_pushButton_add_group_clicked();

    void on_pushButton_delete_group_clicked();
    vector<double>* read_groups();
    void read_data(QString filePath, vector<double>* groups);
    void write_data(const std::vector<std::vector<Participant>>& participants);
    void processing_data( std::vector<std::vector<Participant>>& participants);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
