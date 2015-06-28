#ifndef RAINBOWSQUARE_H
#define RAINBOWSQUARE_H
#include"square.h"

class rainbowsquare:public square
{
public:
    explicit rainbowsquare(QWidget *parent,int col,int row,int type);
    virtual ~rainbowsquare();
    virtual void removesquare();
};

#endif // RAINBOWSQUARE_H
