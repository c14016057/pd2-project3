#include "resultwindow.h"
#include "ui_resultwindow.h"

resultwindow::resultwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::resultwindow)
{
    ui->setupUi(this);
}

resultwindow::~resultwindow()
{
    delete ui;
}

void resultwindow::on_pushButton_clicked()
{
    emit back();
}
void resultwindow::setresult(int score,int star){
    ui->lcdNumber->display(score);
    ui->lcdNumber_2->display(star);

}
