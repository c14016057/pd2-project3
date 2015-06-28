#include "gamewindow.h"
#include "ui_gamewindow.h"
gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    result=new resultwindow;
    connect(result,SIGNAL(back()),this,SLOT(colsegame()));
    int i,j;
    lightsquare=0;
    srand(unsigned(time(NULL)));
    for(i=0;i<10;i++)
        for(j=0;j<15;j++)
           squarematrix[i][j]=new square(ui->gamegorad,j,i,rand()%5+1);
    for(i=0;i<10;i++)
        for(j=0;j<15;j++){
            connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
            connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
            deletematrix[i][j]=0;}
    score=0;
    chance=40;
    star=0;
    gameboradtimer.start(100,this);

}

gamewindow::~gamewindow()
{   emit quit(star,score);
    delete ui;

}

void gamewindow::on_pushButton_clicked()
{


}
void gamewindow::exchange(int row, int col){
    int i,j;
    lightsquare++;
    squarematrix[row][col]->setLight();
    if(lightsquare==1) {
        first_lightsquare_row=row;
        first_lightsquare_col=col;}
    else if(lightsquare==2){
        lightsquare=0;
        second_lightsquare_row=row;
        second_lightsquare_col=col;
        squarematrix[row][col]->setType(squarematrix[row][col]->Type);
        squarematrix[first_lightsquare_row][first_lightsquare_col]->setType(squarematrix[first_lightsquare_row][first_lightsquare_col]->Type);
        if(((first_lightsquare_col-second_lightsquare_col)*(first_lightsquare_col-second_lightsquare_col)
                +(first_lightsquare_row-second_lightsquare_row)*(first_lightsquare_row-second_lightsquare_row))==1)
           {/*int temp=squarematrix[first_lightsquare_row][first_lightsquare_col]->Type;
            squarematrix[first_lightsquare_row][first_lightsquare_col]->setType(squarematrix[second_lightsquare_row][second_lightsquare_col]->Type);
            squarematrix[second_lightsquare_row][second_lightsquare_col]->setType(temp);*/
            if(squarematrix[first_lightsquare_row][first_lightsquare_col]->Type==21) {if(squarematrix[second_lightsquare_row][second_lightsquare_col]->Type==21) {for(i=0;i<10;i++) for(j=0;j<15;j++) deletematrix[i][j]=1;
                                                                                                                                                                  deletematrix[second_lightsquare_row][second_lightsquare_col]=1;
                                                                                                                                                                  chance--;
                                                                                                                                                                  return;}
                                                                                      else for(i=0;i<10;i++) for(j=0;j<15;j++) if(squarematrix[i][j]->Color==squarematrix[second_lightsquare_row][second_lightsquare_col]->Color) deletematrix[i][j]=1;
                                                                                      deletematrix[first_lightsquare_row][first_lightsquare_col]=1;
                                                                                      chance--;
                                                                                      return;}
            else if(squarematrix[second_lightsquare_row][second_lightsquare_col]->Type==21) {for(i=0;i<10;i++) for(j=0;j<15;j++) if(squarematrix[i][j]->Color==squarematrix[first_lightsquare_row][first_lightsquare_col]->Color) deletematrix[i][j]=1;
                                                                                             deletematrix[second_lightsquare_row][second_lightsquare_col]=1;
                                                                                             chance--;
                                                                                             return;}

            /*square * temp=squarematrix[first_lightsquare_row][first_lightsquare_col];
                 disconnect(squarematrix[first_lightsquare_row][first_lightsquare_col],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                 disconnect(squarematrix[first_lightsquare_row][first_lightsquare_col],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                 disconnect(squarematrix[second_lightsquare_row][second_lightsquare_col],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                 disconnect(squarematrix[second_lightsquare_row][second_lightsquare_col],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                 squarematrix[first_lightsquare_row][first_lightsquare_col]=squarematrix[second_lightsquare_row][second_lightsquare_col];
                 squarematrix[first_lightsquare_row][first_lightsquare_col]->setGeometry(first_lightsquare_col,first_lightsquare_row);
                 squarematrix[second_lightsquare_row][second_lightsquare_col]=temp;
                 squarematrix[second_lightsquare_row][second_lightsquare_col]->setGeometry(second_lightsquare_col,second_lightsquare_row);
                 squarematrix[second_lightsquare_row][second_lightsquare_col]->show();
                 squarematrix[first_lightsquare_row][first_lightsquare_col]->show();
                 squarematrix[first_lightsquare_row][first_lightsquare_col]->setType(squarematrix[first_lightsquare_row][first_lightsquare_col]->Type);
                 squarematrix[second_lightsquare_row][second_lightsquare_col]->setType(squarematrix[second_lightsquare_row][second_lightsquare_col]->Type);
                 connect(squarematrix[first_lightsquare_row][first_lightsquare_col],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                 connect(squarematrix[first_lightsquare_row][first_lightsquare_col],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                 connect(squarematrix[second_lightsquare_row][second_lightsquare_col],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                 connect(squarematrix[second_lightsquare_row][second_lightsquare_col],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                 */
                 if(!checkmoveable(first_lightsquare_row,first_lightsquare_col,second_lightsquare_row,second_lightsquare_col)) return;
                 chance--;
                 int temp=squarematrix[first_lightsquare_row][first_lightsquare_col]->Type;
                 disconnect(squarematrix[first_lightsquare_row][first_lightsquare_col],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                 disconnect(squarematrix[first_lightsquare_row][first_lightsquare_col],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                 delete squarematrix[first_lightsquare_row][first_lightsquare_col];
                 squarematrix[first_lightsquare_row][first_lightsquare_col]=NULL;
                 disconnect(squarematrix[second_lightsquare_row][second_lightsquare_col],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                 disconnect(squarematrix[second_lightsquare_row][second_lightsquare_col],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                 squarematrix[first_lightsquare_row][first_lightsquare_col]=squarematrix[second_lightsquare_row][second_lightsquare_col];
                 squarematrix[first_lightsquare_row][first_lightsquare_col]->setGeometry(first_lightsquare_col,first_lightsquare_row);
                 squarematrix[first_lightsquare_row][first_lightsquare_col]->show();
                 connect(squarematrix[first_lightsquare_row][first_lightsquare_col],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                 connect(squarematrix[first_lightsquare_row][first_lightsquare_col],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                 squarematrix[second_lightsquare_row][second_lightsquare_col]=NULL;
                 if(temp==21) squarematrix[second_lightsquare_row][second_lightsquare_col]=new rainbowsquare(ui->gamegorad,second_lightsquare_col,second_lightsquare_row,temp);
                 else if(temp>14) squarematrix[second_lightsquare_row][second_lightsquare_col]=new blocksquare(ui->gamegorad,second_lightsquare_col,second_lightsquare_row,temp);
                 else if(temp>10) squarematrix[second_lightsquare_row][second_lightsquare_col]=new colsquare(ui->gamegorad,second_lightsquare_col,second_lightsquare_row,temp);
                 else if(temp>5) squarematrix[second_lightsquare_row][second_lightsquare_col]=new rowsquare(ui->gamegorad,second_lightsquare_col,second_lightsquare_row,temp);
                 else  squarematrix[second_lightsquare_row][second_lightsquare_col]=new square(ui->gamegorad,second_lightsquare_col,second_lightsquare_row,temp);
                 squarematrix[second_lightsquare_row][second_lightsquare_col]->show();
                 connect(squarematrix[second_lightsquare_row][second_lightsquare_col],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                 connect(squarematrix[second_lightsquare_row][second_lightsquare_col],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));

            }





        else{
            squarematrix[first_lightsquare_row][first_lightsquare_col]->setType(squarematrix[first_lightsquare_row][first_lightsquare_col]->Type);
            squarematrix[second_lightsquare_row][second_lightsquare_col]->setType(squarematrix[second_lightsquare_row][second_lightsquare_col]->Type);
            }

    }
}
void gamewindow::check(){
    int i,j;
    //00000//
        for(j=2;j<13;j++)
            for(i=0;i<10;i++)
                if(*squarematrix[i][j]==*squarematrix[i][j-1]&&
                   *squarematrix[i][j]==*squarematrix[i][j-2]&&
                   *squarematrix[i][j]==*squarematrix[i][j+1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+2]
                   )
                 {deletesquare(i,j);
                  deletesquare(i,j-1);
                  deletesquare(i,j-2);
                  deletesquare(i,j+1);
                  deletesquare(i,j+2);
                  squarematrix[i][j]=new rainbowsquare(ui->gamegorad,j,i,21);
                  squarematrix[i][j]->show();
                  connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                  //squarematrix[i][j-1]=new square(ui->gamegorad,j-1,i,rand()%5+1);
                  //squarematrix[i][j-1]->show();
                  //connect(squarematrix[i][j-1],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  newsquare(i,j-1);
                  newsquare(i,j-2);
                  newsquare(i,j+1);
                  newsquare(i,j+2);

                  return;
                 }

        /*0
          0
          0
          0
          0*/
        for(i=2;i<8;i++)
            for(j=0;j<15;j++)
                if(*squarematrix[i][j]==*squarematrix[i-1][j]&&
                   *squarematrix[i][j]==*squarematrix[i-2][j]&&
                   *squarematrix[i][j]==*squarematrix[i+1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+2][j]
                   )
                 {deletesquare(i,j);
                  deletesquare(i-1,j);
                  deletesquare(i-2,j);
                  deletesquare(i+1,j);
                  deletesquare(i+2,j);
                  squarematrix[i][j]=new rainbowsquare(ui->gamegorad,j,i,21);
                  squarematrix[i][j]->show();
                  connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                  newsquare(i-1,j);
                  newsquare(i-2,j);
                  newsquare(i+1,j);
                  newsquare(i+2,j);

                  return;
                 }
        /*0
          0
          000*/
        for(i=2;i<10;i++)
            for(j=0;j<13;j++)
                if(*squarematrix[i][j]==*squarematrix[i-1][j]&&
                   *squarematrix[i][j]==*squarematrix[i-2][j]&&
                   *squarematrix[i][j]==*squarematrix[i][j+1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+2]
                   )
                 {int color=squarematrix[i][j]->Color;
                  deletesquare(i,j);
                  deletesquare(i-1,j);
                  deletesquare(i-2,j);
                  deletesquare(i,j+1);
                  deletesquare(i,j+2);
                  squarematrix[i][j]=new blocksquare(ui->gamegorad,j,i,15+color);
                  squarematrix[i][j]->show();
                  connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                  newsquare(i-1,j);
                  newsquare(i-2,j);
                  newsquare(i,j+1);
                  newsquare(i,j+2);

                  return;
                 }
        /*  0
            0
          000*/
        for(i=2;i<10;i++)
            for(j=2;j<15;j++)
                if(*squarematrix[i][j]==*squarematrix[i-1][j]&&
                   *squarematrix[i][j]==*squarematrix[i-2][j]&&
                   *squarematrix[i][j]==*squarematrix[i][j-1]&&
                   *squarematrix[i][j]==*squarematrix[i][j-2]
                   )
                 {int color=squarematrix[i][j]->Color;
                  deletesquare(i,j);
                  deletesquare(i-1,j);
                  deletesquare(i-2,j);
                  deletesquare(i,j-1);
                  deletesquare(i,j-2);
                  squarematrix[i][j]=new blocksquare(ui->gamegorad,j,i,15+color);
                  squarematrix[i][j]->show();
                  connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                  newsquare(i-1,j);
                  newsquare(i-2,j);
                  newsquare(i,j-1);
                  newsquare(i,j-2);

                  return;
                 }
        /*000
          0
          0  */
        for(i=0;i<8;i++)
            for(j=0;j<13;j++)
                if(*squarematrix[i][j]==*squarematrix[i+1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+2][j]&&
                   *squarematrix[i][j]==*squarematrix[i][j+1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+2]
                   )
                 {int color=squarematrix[i][j]->Color;
                  deletesquare(i,j);
                  deletesquare(i+1,j);
                  deletesquare(i+2,j);
                  deletesquare(i,j+1);
                  deletesquare(i,j+2);
                  squarematrix[i][j]=new blocksquare(ui->gamegorad,j,i,15+color);
                  squarematrix[i][j]->show();
                  connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                  newsquare(i+1,j);
                  newsquare(i+2,j);
                  newsquare(i,j+1);
                  newsquare(i,j+2);

                  return;
                 }
        /*000
            0
            0*/
        for(i=0;i<8;i++)
            for(j=2;j<15;j++)
                if(*squarematrix[i][j]==*squarematrix[i+1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+2][j]&&
                   *squarematrix[i][j]==*squarematrix[i][j-1]&&
                   *squarematrix[i][j]==*squarematrix[i][j-2]
                   )
                 {int color=squarematrix[i][j]->Color;
                  deletesquare(i,j);
                  deletesquare(i+1,j);
                  deletesquare(i+2,j);
                  deletesquare(i,j-1);
                  deletesquare(i,j-2);
                  squarematrix[i][j]=new blocksquare(ui->gamegorad,j,i,15+color);
                  squarematrix[i][j]->show();
                  connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                  newsquare(i+1,j);
                  newsquare(i+2,j);
                  newsquare(i,j-1);
                  newsquare(i,j-2);

                  return;
                 }
        /*0000*/
        for(i=0;i<10;i++)
            for(j=1;j<13;j++)
                if(*squarematrix[i][j]==*squarematrix[i][j-1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+2]
                   )
                 {int color=squarematrix[i][j]->Color;
                  deletesquare(i,j);
                  deletesquare(i,j-1);
                  deletesquare(i,j+1);
                  deletesquare(i,j+2);
                  squarematrix[i][j]=new colsquare(ui->gamegorad,j,i,10+color);
                  squarematrix[i][j]->show();
                  connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                  newsquare(i,j-1);
                  newsquare(i,j+1);
                  newsquare(i,j+2);

                  return;
                 }
        /*0
          0
          0
          0*/
        for(i=1;i<8;i++)
            for(j=0;j<15;j++)
                if(*squarematrix[i][j]==*squarematrix[i-1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+2][j]
                   )
                 {int color=squarematrix[i][j]->Color;
                  deletesquare(i,j);
                  deletesquare(i-1,j);
                  deletesquare(i+1,j);
                  deletesquare(i+2,j);
                  squarematrix[i][j]=new rowsquare(ui->gamegorad,j,i,5+color);
                  squarematrix[i][j]->show();
                  connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                  newsquare(i-1,j);
                  newsquare(i+1,j);
                  newsquare(i+2,j);

                  return;
                 }
        /*000*/
        for(i=0;i<10;i++)
            for(j=1;j<14;j++)
                if(*squarematrix[i][j]==*squarematrix[i][j-1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+1]
                   )
                 {deletesquare(i,j);
                  deletesquare(i,j-1);
                  deletesquare(i,j+1);
                  squarematrix[i][j]=new square(ui->gamegorad,j,i,rand()%5+1);
                  squarematrix[i][j]->show();
                  connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                  newsquare(i,j-1);
                  newsquare(i,j+1);

                  return;
                 }
        /*0
          0
          0*/
        for(i=1;i<9;i++)
            for(j=0;j<15;j++)
                if(*squarematrix[i][j]==*squarematrix[i-1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+1][j]
                   )
                 {deletesquare(i,j);
                  deletesquare(i-1,j);
                  deletesquare(i+1,j);
                  squarematrix[i][j]=new square(ui->gamegorad,j,i,rand()%5+1);
                  squarematrix[i][j]->show();
                  connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
                  connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
                  newsquare(i-1,j);
                  newsquare(i+1,j);

                  return;
                 }


}
void gamewindow::timerEvent(QTimerEvent *event){
    if(event->timerId()==gameboradtimer.timerId()){
            deleteall();
            newall();
            check();
            checkstar();
            ui->scorelcdNumber->display(score);
            ui->chancelcdNumber->display(chance);
            ui->starlcdNumber->display(star);
            checkover();
        }
    else  gamewindow::timerEvent(event);
}
void gamewindow::newsquare(int i, int j){
    if(squarematrix[i][j]) return;
    if(i==0) {squarematrix[i][j]=new square(ui->gamegorad,j,i,rand()%5+1);
              squarematrix[i][j]->show();
              connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
              connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
              return;}
    if(!squarematrix[i-1][j]) newsquare(i-1,j);
    disconnect(squarematrix[i-1][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
    disconnect(squarematrix[i-1][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
    squarematrix[i][j]=squarematrix[i-1][j];
    squarematrix[i][j]->setGeometry(j,i);
    squarematrix[i][j]->show();
    connect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
    connect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
    squarematrix[i-1][j]=NULL;
    newsquare(i-1,j);
}
void gamewindow::deletesquare(int i, int j){
    if(squarematrix[i][j]==NULL) return;
    if(i<0||i>9||j<0||j>14) return;
    score++;
    squarematrix[i][j]->removesquare();
    disconnect(squarematrix[i][j],SIGNAL(bepushed(int,int)),this,SLOT(exchange(int,int)));
    disconnect(squarematrix[i][j],SIGNAL(removesignal(int,int,int)),this,SLOT(remove_by_type(int,int,int)));
    delete squarematrix[i][j];
    squarematrix[i][j]=NULL;
}
void gamewindow::remove_by_type(int row, int col, int type){
    int i,j;
    if (type==2) for(j=0;j<15;j++) deletematrix[row][j]=1;
    else if (type==3) for(i=0;i<10;i++) deletematrix[i][col]=1;
    else if (type==4) {if(row-1>0&&col-1>0) deletematrix[row-1][col-1]=1;
                       if(row-1>0) deletematrix[row-1][col]=1;
                       if(row-1>0&&col+1<15) deletematrix[row-1][col+1]=1;
                       if(col-1>0) deletematrix[row][col-1]=1;
                       if(col+1<15) deletematrix[row][col+1]=1;
                       if(row+1<10&&col-1>0) deletematrix[row+1][col-1]=1;
                       if(row+1<10) deletematrix[row+1][col]=1;
                       if(row+1<10&&col+1<15) deletematrix[row+1][col+1]=1;}
  /*  else if(type==5) {int color=(rand()%5+1);
                       for(i=0;i<10;i++)
                         for(j=0;j<15;j++)
                            if(squarematrix[i][j]) if(squarematrix[i][j]->Color==color) deletematrix[i][j]=1;

                      }*/
}
void gamewindow::newall(){
    int i,j;
    for(i=9;i>=0;--i)
        for(j=0;j<15;++j)
           newsquare(i,j);
}
void gamewindow::deleteall(){
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<15;j++)
            if(deletematrix[i][j]) {deletesquare(i,j);
                                    deletematrix[i][j]=0;}
}

bool gamewindow::checkmoveable(int frow, int fcol, int srow, int scol){
    int temp=squarematrix[frow][fcol]->Type;
    squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
    squarematrix[srow][scol]->setType(temp);
    int i,j;
    //00000//
        for(j=2;j<13;j++)
            for(i=0;i<10;i++)
                if(*squarematrix[i][j]==*squarematrix[i][j-1]&&
                   *squarematrix[i][j]==*squarematrix[i][j-2]&&
                   *squarematrix[i][j]==*squarematrix[i][j+1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+2]
                   ) {temp=squarematrix[frow][fcol]->Type;
                      squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
                      squarematrix[srow][scol]->setType(temp);
                      return true;}


        /*0
          0
          0
          0
          0*/
        for(i=2;i<8;i++)
            for(j=0;j<15;j++)
                if(*squarematrix[i][j]==*squarematrix[i-1][j]&&
                   *squarematrix[i][j]==*squarematrix[i-2][j]&&
                   *squarematrix[i][j]==*squarematrix[i+1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+2][j]
                   )
                {temp=squarematrix[frow][fcol]->Type;
                                      squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
                                      squarematrix[srow][scol]->setType(temp);
                                      return true;}
        /*0
          0
          000*/
        for(i=2;i<10;i++)
            for(j=0;j<13;j++)
                if(*squarematrix[i][j]==*squarematrix[i-1][j]&&
                   *squarematrix[i][j]==*squarematrix[i-2][j]&&
                   *squarematrix[i][j]==*squarematrix[i][j+1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+2]
                   )
                {temp=squarematrix[frow][fcol]->Type;
                                      squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
                                      squarematrix[srow][scol]->setType(temp);
                                      return true;}
        /*  0
            0
          000*/
        for(i=2;i<10;i++)
            for(j=2;j<15;j++)
                if(*squarematrix[i][j]==*squarematrix[i-1][j]&&
                   *squarematrix[i][j]==*squarematrix[i-2][j]&&
                   *squarematrix[i][j]==*squarematrix[i][j-1]&&
                   *squarematrix[i][j]==*squarematrix[i][j-2]
                   )
                {temp=squarematrix[frow][fcol]->Type;
                                      squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
                                      squarematrix[srow][scol]->setType(temp);
                                      return true;}
        /*000
          0
          0  */
        for(i=0;i<8;i++)
            for(j=0;j<13;j++)
                if(*squarematrix[i][j]==*squarematrix[i+1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+2][j]&&
                   *squarematrix[i][j]==*squarematrix[i][j+1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+2]
                   )
                {temp=squarematrix[frow][fcol]->Type;
                                      squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
                                      squarematrix[srow][scol]->setType(temp);
                                      return true;}
        /*000
            0
            0*/
        for(i=0;i<8;i++)
            for(j=2;j<15;j++)
                if(*squarematrix[i][j]==*squarematrix[i+1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+2][j]&&
                   *squarematrix[i][j]==*squarematrix[i][j-1]&&
                   *squarematrix[i][j]==*squarematrix[i][j-2]
                   )
                {temp=squarematrix[frow][fcol]->Type;
                                      squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
                                      squarematrix[srow][scol]->setType(temp);
                                      return true;}
        /*0000*/
        for(i=0;i<10;i++)
            for(j=1;j<13;j++)
                if(*squarematrix[i][j]==*squarematrix[i][j-1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+2]
                   )
                {temp=squarematrix[frow][fcol]->Type;
                                      squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
                                      squarematrix[srow][scol]->setType(temp);
                                      return true;}
        /*0
          0
          0
          0*/
        for(i=1;i<8;i++)
            for(j=0;j<15;j++)
                if(*squarematrix[i][j]==*squarematrix[i-1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+2][j]
                   )
                {temp=squarematrix[frow][fcol]->Type;
                                      squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
                                      squarematrix[srow][scol]->setType(temp);
                                      return true;}
        /*000*/
        for(i=0;i<10;i++)
            for(j=1;j<14;j++)
                if(*squarematrix[i][j]==*squarematrix[i][j-1]&&
                   *squarematrix[i][j]==*squarematrix[i][j+1]
                   )
                {temp=squarematrix[frow][fcol]->Type;
                                      squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
                                      squarematrix[srow][scol]->setType(temp);
                                      return true;}
        /*0
          0
          0*/
        for(i=1;i<9;i++)
            for(j=0;j<15;j++)
                if(*squarematrix[i][j]==*squarematrix[i-1][j]&&
                   *squarematrix[i][j]==*squarematrix[i+1][j]
                   )
                {temp=squarematrix[frow][fcol]->Type;
                                      squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
                                      squarematrix[srow][scol]->setType(temp);
                                      return true;}
        temp=squarematrix[frow][fcol]->Type;
        squarematrix[frow][fcol]->setType(squarematrix[srow][scol]->Type);
        squarematrix[srow][scol]->setType(temp);
        return false;



}
void gamewindow::checkstar(){
    if(score<500) star=0;
    if(score>500&&score<1000) star=1;
    if(score>1000&&score<2000) star=2;
    if(score>2000) star=3;
}
void gamewindow::checkover(){
    if(chance<=35) {result->setresult(score,star);
    result->show();
    this->hide();
    gameboradtimer.stop();}
}
void gamewindow::colsegame(){
    emit quit(star,score);
    this->close();
    result->close();
}
