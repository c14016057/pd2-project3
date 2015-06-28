#include "rainbowsquare.h"

rainbowsquare::rainbowsquare(QWidget *parent, int col, int row, int type) :square(parent,col,row,type){
}
rainbowsquare::~rainbowsquare(){

}
void rainbowsquare::removesquare(){
    emit removesignal(Row,Col,5);
}
