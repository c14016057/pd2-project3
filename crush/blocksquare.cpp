#include "blocksquare.h"
blocksquare::~blocksquare(){

}
void blocksquare::removesquare(){
    emit removesignal(Row,Col,4);
}
