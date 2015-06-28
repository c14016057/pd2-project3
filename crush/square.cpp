#include "square.h"
square::square(QWidget *parent,int col,int row,int type) : QObject(parent)
{
    Col=col;
    Row=row;
    Type=type;
    Color=type>20?6:(type-1)%5+1;
    candy=new QPushButton(parent);
    candy->setFlat(true);
    candy->setGeometry(Col*50+1,Row*50+1,48,48);
    switch(Type){
        case 1:
            candy->setIcon(QIcon(":/red.png"));
            break;
        case 2:
            candy->setIcon(QIcon(":/blue.png"));
            break;
        case 3:
            candy->setIcon(QIcon(":/green.png"));
            break;
        case 4:
            candy->setIcon(QIcon(":/purple.png"));
            break;
        case 5:
            candy->setIcon(QIcon(":/orange.png"));
            break;
    case 6:
        candy->setIcon(QIcon(":/redrow.png"));
        break;
    case 7:
        candy->setIcon(QIcon(":/bluerow.png"));
        break;
    case 8:
        candy->setIcon(QIcon(":/greenrow.png"));
        break;
    case 9:
        candy->setIcon(QIcon(":/purplerow.png"));
        break;
    case 10:
        candy->setIcon(QIcon(":/orangerow.png"));
        break;
    case 11:
        candy->setIcon(QIcon(":/redcol.png"));
        break;
    case 12:
        candy->setIcon(QIcon(":/bluecol.png"));
        break;
    case 13:
        candy->setIcon(QIcon(":/greencol.png"));
        break;
    case 14:
        candy->setIcon(QIcon(":/purplecol.png"));
        break;
    case 15:
        candy->setIcon(QIcon(":/orangecol.png"));
        break;
    case 16:
        candy->setIcon(QIcon(":/redblock.png"));
        break;
    case 17:
        candy->setIcon(QIcon(":/blueblock.png"));
        break;
    case 18:
        candy->setIcon(QIcon(":/greenblock.png"));
        break;
    case 19:
        candy->setIcon(QIcon(":/purpleblock.png"));
        break;
    case 20:
        candy->setIcon(QIcon(":/orangeblock.png"));
        break;
    default:
        candy->setIcon(QIcon(":/rainbowblock.png"));

    }
    candy->setIconSize(QSize(48,48));
    connect(candy,SIGNAL(clicked(bool)),this,SLOT(on_button_clecked()));
    //qbtimr.start(1000,this);
}

void square::falldown(){

        Col=Col+5;
        candy->setGeometry(Row,Col,50,50);

}
//void square::timerEvent(QTimerEvent *event){
//    if(event->timerId()==qbtimr.timerId()){
//        falldown();
//    }
//    else  square::timerEvent(event);
//}
square::~square(){
 delete candy;
}
void square::on_button_clecked(){
    emit bepushed(Row,Col);


}
void square::setType(int t){
    Type=t;
    Color=t>20?6:(t-1)%5+1;
    switch(Type){
        case 1:
            candy->setIcon(QIcon(":/red.png"));
            break;
        case 2:
            candy->setIcon(QIcon(":/blue.png"));
            break;
        case 3:
            candy->setIcon(QIcon(":/green.png"));
            break;
        case 4:
            candy->setIcon(QIcon(":/purple.png"));
            break;
        case 5:
            candy->setIcon(QIcon(":/orange.png"));
            break;
        case 6:
            candy->setIcon(QIcon(":/redrow.png"));
            break;
        case 7:
            candy->setIcon(QIcon(":/bluerow.png"));
            break;
        case 8:
            candy->setIcon(QIcon(":/greenrow.png"));
            break;
        case 9:
            candy->setIcon(QIcon(":/purplerow.png"));
            break;
        case 10:
            candy->setIcon(QIcon(":/orangerow.png"));
            break;
        case 11:
            candy->setIcon(QIcon(":/redcol.png"));
            break;
        case 12:
            candy->setIcon(QIcon(":/bluecol.png"));
            break;
        case 13:
            candy->setIcon(QIcon(":/greencol.png"));
            break;
        case 14:
            candy->setIcon(QIcon(":/purplecol.png"));
            break;
        case 15:
            candy->setIcon(QIcon(":/orangecol.png"));
            break;
        case 16:
            candy->setIcon(QIcon(":/redblock.png"));
            break;
        case 17:
            candy->setIcon(QIcon(":/blueblock.png"));
            break;
        case 18:
            candy->setIcon(QIcon(":/greenblock.png"));
            break;
        case 19:
            candy->setIcon(QIcon(":/purpleblock.png"));
            break;
        case 20:
            candy->setIcon(QIcon(":/orangeblock.png"));
            break;
        default:
            candy->setIcon(QIcon(":/rainbowblock.png"));
    }

}
void square::setLight(){
    switch(Type){
    case 1:
        candy->setIcon(QIcon(":/redlight.png"));
        break;
    case 2:
        candy->setIcon(QIcon(":/bluelight.png"));
        break;
    case 3:
        candy->setIcon(QIcon(":/greenlight.png"));
        break;
    case 4:
        candy->setIcon(QIcon(":/purplelight.png"));
        break;
    case 5:
        candy->setIcon(QIcon(":/orangelight.png"));
        break;
    case 6:
        candy->setIcon(QIcon(":/redrowlight.png"));
        break;
    case 7:
        candy->setIcon(QIcon(":/bluerowlight.png"));
        break;
    case 8:
        candy->setIcon(QIcon(":/greenrowlight.png"));
        break;
    case 9:
        candy->setIcon(QIcon(":/purplerowlight.png"));
        break;
    case 10:
        candy->setIcon(QIcon(":/orangerowlight.png"));
        break;
    case 11:
        candy->setIcon(QIcon(":/redcollight.png"));
        break;
    case 12:
        candy->setIcon(QIcon(":/bluecollight.png"));
        break;
    case 13:
        candy->setIcon(QIcon(":/greencollight.png"));
        break;
    case 14:
        candy->setIcon(QIcon(":/purplecollight.png"));
        break;
    case 15:
        candy->setIcon(QIcon(":/orangecollight.png"));
        break;
    case 16:
        candy->setIcon(QIcon(":/redblocklight.png"));
        break;
    case 17:
        candy->setIcon(QIcon(":/blueblocklight.png"));
        break;
    case 18:
        candy->setIcon(QIcon(":/greenblocklight.png"));
        break;
    case 19:
        candy->setIcon(QIcon(":/purpleblocklight.png"));
        break;
    case 20:
        candy->setIcon(QIcon(":/orangeblocklight.png"));
        break;
    default:
        candy->setIcon(QIcon(":/rainbowblocklight.png"));
    }
}
bool square::operator ==(square & s){
    if(this->Color==s.Color) return true;
    else return false;
}
void square::show(){
    candy->show();
}
void square::setGeometry(int col, int row){
    Col=col;
    Row=row;
    candy->setGeometry(Col*50+1,Row*50+1,48,48);
}
void square::removesquare(){
    emit removesignal(Row,Col,1);
}
