#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include"square.h"
#include<ctime>
#include"rowsquare.h"
#include"colsquare.h"
#include"blocksquare.h"
#include"rainbowsquare.h"
#include"resultwindow.h"
namespace Ui {
class gamewindow;
}

class gamewindow : public QWidget
{
    Q_OBJECT

public:
    explicit gamewindow(QWidget *parent = 0);
    ~gamewindow();
    void check();
signals:
    void quit(int star,int score);

private slots:
    void on_pushButton_clicked();
    void exchange(int row,int col);
    void remove_by_type(int row ,int col, int type);
    void colsegame();

private:
    Ui::gamewindow *ui;
    square *squarematrix[10][15];
    int lightsquare;
    int first_lightsquare_row;
    int first_lightsquare_col;
    int second_lightsquare_row;
    int second_lightsquare_col;
    QBasicTimer gameboradtimer;
    void timerEvent(QTimerEvent *event);
    void newsquare(int i,int j);
    void deletesquare(int i,int j);
    void newall();
    void deleteall();
    int deletematrix[10][15];
    bool checkmoveable(int frow,int fcol,int srow,int scol);
    int score;
    int chance;
    int star;
    void checkstar();
    resultwindow *result;
    void checkover();
};

#endif // GAMEWINDOW_H
