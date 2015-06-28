#include "rowsquare.h"
rowsquare::~rowsquare(){

}
void rowsquare::removesquare(){
    emit removesignal(Row,Col,2);
}
