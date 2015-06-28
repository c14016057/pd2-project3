#include "colsquare.h"
colsquare::~colsquare(){

}
void colsquare::removesquare(){
    emit removesignal(Row,Col,3);
}
