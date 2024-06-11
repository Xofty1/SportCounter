#include "createcompetition.h"
#include "ui_createcompetition.h"

CreateCompetition::CreateCompetition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateCompetition)
{
    ui->setupUi(this);
    ui->radioButton_olympic_games->setChecked(true);
}

CreateCompetition::~CreateCompetition()
{
    delete ui;
}

void CreateCompetition::on_pushButton_add_group_clicked()
{
    // Увеличиваем счетчик групп
    groupCount++;

    // Создаем два новых QSpinBox
    QSpinBox *spinbox1 = new QSpinBox(this);
    QSpinBox *spinbox2 = new QSpinBox(this);

    spinbox1->setRange(2000, 2100);
    spinbox2->setRange(2000, 2100);

    // Добавляем их в gridLayout вашего окна на новую строку
    ui->gridLayout_groups->addWidget(spinbox1, groupCount - 1, 0); // Добавляем в столбец 0
    ui->gridLayout_groups->addWidget(spinbox2, groupCount - 1, 1); // Добавляем в столбец 1

    // Устанавливаем stretch-фактор для новой строки, чтобы она оставалась на верху
    ui->gridLayout_groups->setRowStretch(groupCount - 1, 0);

    // Устанавливаем максимальный stretch-фактор для последней строки, чтобы пустое пространство было снизу
    ui->gridLayout_groups->setRowStretch(groupCount, 1);
}

void CreateCompetition::on_pushButton_delete_group_clicked()
{
    if (groupCount == 0) return; // Проверяем, есть ли что удалять

    // Получаем элементы ячеек текущей строки
    QLayoutItem *item1 = ui->gridLayout_groups->itemAtPosition(groupCount - 1, 0);
    QLayoutItem *item2 = ui->gridLayout_groups->itemAtPosition(groupCount - 1, 1);

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

    // Уменьшаем счетчик групп
    groupCount--;

    // Перерисовываем сетку
    ui->gridLayout_groups->invalidate();

    // Устанавливаем максимальный stretch-фактор для последней строки, чтобы пустое пространство было снизу
    ui->gridLayout_groups->setRowStretch(groupCount, 1);
}

vector<double>* CreateCompetition::read_groups(){
    vector<double> *groups = new vector<double>();
    for (int i = 0; i <groupCount; ++i) {
        // Получаем элемент в ячейке (i, 0) - это первый столбец
        QSpinBox *spinbox1 = qobject_cast<QSpinBox*>(ui->gridLayout_groups->itemAtPosition(i, 0)->widget());
        // Получаем элемент в ячейке (i, 1) - это второй столбец
        QSpinBox *spinbox2 = qobject_cast<QSpinBox*>(ui->gridLayout_groups->itemAtPosition(i, 1)->widget());

        if (spinbox1 && spinbox2) {
            // Считываем текст из QLineEdit
            QString text1 = spinbox1->text();
            QString text2 = spinbox2->text();
            groups->push_back(text1.toDouble());
            groups->push_back(text2.toDouble());
        }
    }
    return groups;
}

void CreateCompetition::on_pushButton_back_clicked()
{
    emit signalGroup(read_groups());
    emit signalCompetitionType(competitionType);
    this->close();
}


void CreateCompetition::on_radioButton_olympic_games_clicked()
{
        competitionType = 0;
}

void CreateCompetition::on_radioButton_biathlon_clicked()
{
    competitionType = 1;
}
