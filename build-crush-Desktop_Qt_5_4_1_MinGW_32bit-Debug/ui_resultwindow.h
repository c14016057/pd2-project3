/********************************************************************************
** Form generated from reading UI file 'resultwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWINDOW_H
#define UI_RESULTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resultwindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QPushButton *pushButton;

    void setupUi(QWidget *resultwindow)
    {
        if (resultwindow->objectName().isEmpty())
            resultwindow->setObjectName(QStringLiteral("resultwindow"));
        resultwindow->resize(850, 600);
        label = new QLabel(resultwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 120, 201, 111));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(72);
        label->setFont(font);
        label_2 = new QLabel(resultwindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 280, 171, 151));
        label_2->setFont(font);
        lcdNumber = new QLCDNumber(resultwindow);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(360, 170, 200, 51));
        lcdNumber_2 = new QLCDNumber(resultwindow);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(360, 350, 200, 51));
        pushButton = new QPushButton(resultwindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(670, 520, 101, 41));

        retranslateUi(resultwindow);

        QMetaObject::connectSlotsByName(resultwindow);
    } // setupUi

    void retranslateUi(QWidget *resultwindow)
    {
        resultwindow->setWindowTitle(QApplication::translate("resultwindow", "Form", 0));
        label->setText(QApplication::translate("resultwindow", "score:", 0));
        label_2->setText(QApplication::translate("resultwindow", "star:", 0));
        pushButton->setText(QApplication::translate("resultwindow", "ok", 0));
    } // retranslateUi

};

namespace Ui {
    class resultwindow: public Ui_resultwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWINDOW_H
