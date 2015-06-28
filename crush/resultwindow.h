#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QWidget>

namespace Ui {
class resultwindow;
}

class resultwindow : public QWidget
{
    Q_OBJECT

public:
    explicit resultwindow(QWidget *parent = 0);
    ~resultwindow();
    void setresult(int score,int star);
    int score;
    int star;
signals:
    void back();

private slots:
    void on_pushButton_clicked();

private:
    Ui::resultwindow *ui;
};

#endif // RESULTWINDOW_H
