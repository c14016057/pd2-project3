#ifndef COLSQUARE_H
#define COLSQUARE_H
#include"square.h"

class colsquare:public square
{
public:
    colsquare(QWidget *parent,int col,int row,int type):square(parent,col,row,type){};
    virtual ~colsquare();
    virtual void removesquare();
};

#endif // COLSQUARE_H
