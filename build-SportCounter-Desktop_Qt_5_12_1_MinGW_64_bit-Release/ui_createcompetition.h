/********************************************************************************
** Form generated from reading UI file 'createcompetition.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECOMPETITION_H
#define UI_CREATECOMPETITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateCompetition
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_groups;
    QPushButton *pushButton_back;
    QGroupBox *groupBox;
    QRadioButton *radioButton_olympic_games;
    QRadioButton *radioButton_biathlon;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_add_group;
    QPushButton *pushButton_delete_group;

    void setupUi(QWidget *CreateCompetition)
    {
        if (CreateCompetition->objectName().isEmpty())
            CreateCompetition->setObjectName(QString::fromUtf8("CreateCompetition"));
        CreateCompetition->resize(1220, 633);
        CreateCompetition->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #292949;\n"
"}"));
        gridLayoutWidget = new QWidget(CreateCompetition);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 90, 361, 521));
        gridLayout_groups = new QGridLayout(gridLayoutWidget);
        gridLayout_groups->setObjectName(QString::fromUtf8("gridLayout_groups"));
        gridLayout_groups->setContentsMargins(0, 0, 0, 0);
        pushButton_back = new QPushButton(CreateCompetition);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(680, 530, 191, 61));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_back->sizePolicy().hasHeightForWidth());
        pushButton_back->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_back->setFont(font);
        pushButton_back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5654A;\n"
"    border: 2px solid #F5654A;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #292949;\n"
"    color: white;\n"
"}"));
        groupBox = new QGroupBox(CreateCompetition);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(500, 30, 561, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Montserrat SemiBold"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	color: white;\n"
"}"));
        radioButton_olympic_games = new QRadioButton(groupBox);
        radioButton_olympic_games->setObjectName(QString::fromUtf8("radioButton_olympic_games"));
        radioButton_olympic_games->setGeometry(QRect(20, 30, 341, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Montserrat SemiBold"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        radioButton_olympic_games->setFont(font2);
        radioButton_olympic_games->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: white;\n"
"}"));
        radioButton_biathlon = new QRadioButton(groupBox);
        radioButton_biathlon->setObjectName(QString::fromUtf8("radioButton_biathlon"));
        radioButton_biathlon->setGeometry(QRect(20, 70, 221, 20));
        radioButton_biathlon->setFont(font2);
        radioButton_biathlon->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: white;\n"
"}"));
        label = new QLabel(CreateCompetition);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 301, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Montserrat SemiBold"));
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:white;\n"
"}"));
        layoutWidget = new QWidget(CreateCompetition);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(320, 40, 101, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_add_group = new QPushButton(layoutWidget);
        pushButton_add_group->setObjectName(QString::fromUtf8("pushButton_add_group"));
        pushButton_add_group->setFont(font);
        pushButton_add_group->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5654A;\n"
"    border: 2px solid #F5654A;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #292949;\n"
"    color: white;\n"
"}"));

        horizontalLayout->addWidget(pushButton_add_group);

        pushButton_delete_group = new QPushButton(layoutWidget);
        pushButton_delete_group->setObjectName(QString::fromUtf8("pushButton_delete_group"));
        pushButton_delete_group->setFont(font);
        pushButton_delete_group->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5654A;\n"
"    border: 2px solid #F5654A;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #292949;\n"
"    color: white;\n"
"}"));

        horizontalLayout->addWidget(pushButton_delete_group);


        retranslateUi(CreateCompetition);

        QMetaObject::connectSlotsByName(CreateCompetition);
    } // setupUi

    void retranslateUi(QWidget *CreateCompetition)
    {
        CreateCompetition->setWindowTitle(QApplication::translate("CreateCompetition", "Form", nullptr));
        pushButton_back->setText(QApplication::translate("CreateCompetition", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272 \321\200\320\260\321\201\321\207\320\265\321\202\320\260\320\274", nullptr));
        groupBox->setTitle(QApplication::translate("CreateCompetition", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\262\320\270\320\264 \321\201\320\276\321\200\320\265\320\262\320\275\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        radioButton_olympic_games->setText(QApplication::translate("CreateCompetition", "\320\234\320\260\320\273\321\213\320\265 \320\276\320\273\320\270\320\274\320\277\320\270\320\271\321\201\320\272\320\270\320\265 \320\270\320\263\321\200\321\213", nullptr));
        radioButton_biathlon->setText(QApplication::translate("CreateCompetition", "\320\221\320\270\320\260\321\202\320\273\320\276\320\275", nullptr));
        label->setText(QApplication::translate("CreateCompetition", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202\320\275\321\213\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        pushButton_add_group->setText(QApplication::translate("CreateCompetition", "+", nullptr));
        pushButton_delete_group->setText(QApplication::translate("CreateCompetition", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateCompetition: public Ui_CreateCompetition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECOMPETITION_H
