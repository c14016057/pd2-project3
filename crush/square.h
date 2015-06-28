#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QLabel>
#include<QtGui>
#include<QFrame>
#include"timer.h"
#include<QBasicTimer>
#include<QPushButton>
class square : public QObject
{
    Q_OBJECT
public:
    explicit square(QWidget *parent,int col,int row,int type);
    virtual ~square();
    virtual void removesquare();
    void falldown();
    int Type;
    int Color;
    void setType(int t);
    void setLight();
    bool operator==(square &);
    void show();
    void setGeometry(int col,int row);
signals:
    void bepushed(int row,int col);
    void removesignal(int row,int col,int type);
public slots:
    void on_button_clecked();
protected:
    int Col;
    int Row;
    QPushButton *candy;
    //QBasicTimer qbtimr;
    //QPushButton *testbutton;
   // void timerEvent(QTimerEvent *event);
    //void paintEnent();

};

#endif // SQUARE_H
