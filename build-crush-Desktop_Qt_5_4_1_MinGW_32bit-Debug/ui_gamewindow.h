/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

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

class Ui_gamewindow
{
public:
    QLabel *gamegorad;
    QPushButton *pushButton;
    QLabel *label;
    QLCDNumber *scorelcdNumber;
    QLabel *label_2;
    QLCDNumber *chancelcdNumber;
    QLabel *label_3;
    QLCDNumber *starlcdNumber;
    QLabel *label_4;

    void setupUi(QWidget *gamewindow)
    {
        if (gamewindow->objectName().isEmpty())
            gamewindow->setObjectName(QStringLiteral("gamewindow"));
        gamewindow->resize(850, 600);
        gamegorad = new QLabel(gamewindow);
        gamegorad->setObjectName(QStringLiteral("gamegorad"));
        gamegorad->setGeometry(QRect(40, 50, 750, 500));
        gamegorad->setStyleSheet(QStringLiteral("border-image: url(:/borad.png);"));
        pushButton = new QPushButton(gamewindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 10, 75, 23));
        label = new QLabel(gamewindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 61, 21));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        scorelcdNumber = new QLCDNumber(gamewindow);
        scorelcdNumber->setObjectName(QStringLiteral("scorelcdNumber"));
        scorelcdNumber->setGeometry(QRect(210, 10, 64, 23));
        label_2 = new QLabel(gamewindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 10, 71, 21));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        chancelcdNumber = new QLCDNumber(gamewindow);
        chancelcdNumber->setObjectName(QStringLiteral("chancelcdNumber"));
        chancelcdNumber->setGeometry(QRect(360, 10, 64, 23));
        label_3 = new QLabel(gamewindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(430, 0, 61, 41));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        starlcdNumber = new QLCDNumber(gamewindow);
        starlcdNumber->setObjectName(QStringLiteral("starlcdNumber"));
        starlcdNumber->setGeometry(QRect(470, 10, 64, 23));
        label_4 = new QLabel(gamewindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(580, 10, 141, 21));
        label_4->setFont(font);

        retranslateUi(gamewindow);

        QMetaObject::connectSlotsByName(gamewindow);
    } // setupUi

    void retranslateUi(QWidget *gamewindow)
    {
        gamewindow->setWindowTitle(QApplication::translate("gamewindow", "gamewindow", 0));
        gamegorad->setText(QString());
        pushButton->setText(QApplication::translate("gamewindow", "start", 0));
        label->setText(QApplication::translate("gamewindow", "score", 0));
        label_2->setText(QApplication::translate("gamewindow", "chance", 0));
        label_3->setText(QApplication::translate("gamewindow", "star", 0));
        label_4->setText(QApplication::translate("gamewindow", "Get 2000 score in 40 move!", 0));
    } // retranslateUi

};

namespace Ui {
    class gamewindow: public Ui_gamewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
