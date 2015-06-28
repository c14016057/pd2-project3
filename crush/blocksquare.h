#ifndef BLOCKSQUARE_H
#define BLOCKSQUARE_H
#include"square.h"

class blocksquare:public square
{
public:
    blocksquare(QWidget *parent,int col,int row,int type):square(parent,col,row,type){};
    virtual ~blocksquare();
    virtual void removesquare();
};

#endif // BLOCKSQUARE_H
