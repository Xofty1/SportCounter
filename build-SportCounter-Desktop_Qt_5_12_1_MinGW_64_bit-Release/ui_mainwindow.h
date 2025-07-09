/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_download_olympic_games;
    QPushButton *pushButton_download_biathlon;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_info;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *pushButton_file_choose;
    QPushButton *pushButton_createCompetition;
    QPushButton *pushButton_answer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1018, 672);
        QFont font;
        font.setFamily(QString::fromUtf8("Montserrat SemiBold"));
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: black;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setFont(font);
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #292949;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_download_olympic_games = new QPushButton(centralWidget);
        pushButton_download_olympic_games->setObjectName(QString::fromUtf8("pushButton_download_olympic_games"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_download_olympic_games->sizePolicy().hasHeightForWidth());
        pushButton_download_olympic_games->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Montserrat SemiBold"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_download_olympic_games->setFont(font1);
        pushButton_download_olympic_games->setLayoutDirection(Qt::LeftToRight);
        pushButton_download_olympic_games->setAutoFillBackground(false);
        pushButton_download_olympic_games->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5654A;\n"
"    border: 2px solid #F5654A;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #292949;\n"
"    color: white;\n"
"}"));

        verticalLayout_2->addWidget(pushButton_download_olympic_games);

        pushButton_download_biathlon = new QPushButton(centralWidget);
        pushButton_download_biathlon->setObjectName(QString::fromUtf8("pushButton_download_biathlon"));
        sizePolicy.setHeightForWidth(pushButton_download_biathlon->sizePolicy().hasHeightForWidth());
        pushButton_download_biathlon->setSizePolicy(sizePolicy);
        pushButton_download_biathlon->setFont(font1);
        pushButton_download_biathlon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5654A;\n"
"    border: 2px solid #F5654A;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #292949;\n"
"    color: white;\n"
"}"));

        verticalLayout_2->addWidget(pushButton_download_biathlon);


        gridLayout_2->addLayout(verticalLayout_2, 2, 2, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton_info = new QPushButton(centralWidget);
        pushButton_info->setObjectName(QString::fromUtf8("pushButton_info"));
        pushButton_info->setFont(font1);
        pushButton_info->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5654A;\n"
"    border: 2px solid #F5654A;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #292949;\n"
"    color: white;\n"
"}"));

        gridLayout_3->addWidget(pushButton_info, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Montserrat SemiBold"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label->setFont(font2);
        label->setToolTipDuration(-1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white;\n"
"    border: 2px solid #F5654A;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"}"));

        horizontalLayout_2->addWidget(label);

        pushButton_file_choose = new QPushButton(centralWidget);
        pushButton_file_choose->setObjectName(QString::fromUtf8("pushButton_file_choose"));
        pushButton_file_choose->setFont(font1);
        pushButton_file_choose->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5654A;\n"
"    border: 2px solid #F5654A;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #292949;\n"
"    color: white;\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_file_choose);


        verticalLayout_3->addLayout(horizontalLayout_2);

        pushButton_createCompetition = new QPushButton(centralWidget);
        pushButton_createCompetition->setObjectName(QString::fromUtf8("pushButton_createCompetition"));
        pushButton_createCompetition->setFont(font1);
        pushButton_createCompetition->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5654A;\n"
"    border: 2px solid #F5654A;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"    margin: 10px 0;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #292949;\n"
"    color: white;\n"
"}"));

        verticalLayout_3->addWidget(pushButton_createCompetition);

        pushButton_answer = new QPushButton(centralWidget);
        pushButton_answer->setObjectName(QString::fromUtf8("pushButton_answer"));
        sizePolicy.setHeightForWidth(pushButton_answer->sizePolicy().hasHeightForWidth());
        pushButton_answer->setSizePolicy(sizePolicy);
        pushButton_answer->setFont(font2);
        pushButton_answer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5654A;\n"
"    border: 2px solid #F5654A;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #292949;\n"
"    color: white;\n"
"}"));

        verticalLayout_3->addWidget(pushButton_answer);


        gridLayout_2->addLayout(verticalLayout_3, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_download_olympic_games->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\260\321\207\320\260\321\202\321\214 \321\210\320\260\320\261\320\273\320\276\320\275 \320\264\320\273\321\217 \320\276\320\273\320\270\320\274\320\277\320\270\320\271\321\201\320\272\320\270\321\205 \320\270\320\263\321\200", nullptr));
        pushButton_download_biathlon->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\260\321\207\320\260\321\202\321\214 \321\210\320\260\320\261\320\273\320\276\320\275 \320\264\320\273\321\217 \320\261\320\270\320\260\321\202\320\273\320\276\320\275\320\260", nullptr));
        pushButton_info->setText(QApplication::translate("MainWindow", "?", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        pushButton_file_choose->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        pushButton_createCompetition->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\320\276\321\200\320\265\320\262\320\275\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        pushButton_answer->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
