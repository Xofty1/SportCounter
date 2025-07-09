/********************************************************************************
** Form generated from reading UI file 'infowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWINDOW_H
#define UI_INFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_info;

    void setupUi(QWidget *InfoWindow)
    {
        if (InfoWindow->objectName().isEmpty())
            InfoWindow->setObjectName(QString::fromUtf8("InfoWindow"));
        InfoWindow->resize(954, 676);
        InfoWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #292949;\n"
"}"));
        horizontalLayout = new QHBoxLayout(InfoWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_info = new QLabel(InfoWindow);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        QFont font;
        font.setFamily(QString::fromUtf8("Montserrat SemiBold"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_info->setFont(font);
        label_info->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:white;\n"
"}"));

        horizontalLayout->addWidget(label_info);


        retranslateUi(InfoWindow);

        QMetaObject::connectSlotsByName(InfoWindow);
    } // setupUi

    void retranslateUi(QWidget *InfoWindow)
    {
        InfoWindow->setWindowTitle(QApplication::translate("InfoWindow", "Form", nullptr));
        label_info->setText(QApplication::translate("InfoWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWindow: public Ui_InfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
