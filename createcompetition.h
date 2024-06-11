#ifndef CREATECOMPETITION_H
#define CREATECOMPETITION_H

#include <QWidget>
#include <QSpinBox>
#include <vector>
using namespace std;
namespace Ui {
class CreateCompetition;
}

class CreateCompetition : public QWidget
{
    Q_OBJECT

public:
    vector<double>* read_groups();
    explicit CreateCompetition(QWidget *parent = nullptr);
    ~CreateCompetition();

private slots:
    void on_pushButton_add_group_clicked();

    void on_pushButton_delete_group_clicked();

    void on_pushButton_back_clicked();

    void on_radioButton_olympic_games_clicked();

    void on_radioButton_biathlon_clicked();

private:
    int competitionType = 0;
    int groupCount = 0;
    Ui::CreateCompetition *ui;

signals:
    void signalGroup(vector<double>*);
    void signalCompetitionType(int);
};

#endif // CREATECOMPETITION_H
