#ifndef ROWSQUARE_H
#define ROWSQUARE_H
#include"square.h"

class rowsquare :public square
{
public:
    explicit rowsquare(QWidget *parent,int col,int row,int type):square(parent, col, row, type){};
    virtual ~rowsquare();
    virtual void removesquare();
};

#endif // ROWSQUARE_H
