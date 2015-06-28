#ifndef SELECTION3_H
#define SELECTION3_H


#include "destroy.h"
#include "grille.h"

class Selection3_H:public Destroy
{
public:
    Selection3_H();
    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode);
    virtual void elimination(Grille * grille[N][N],Grille * clicked);
    virtual int condition(Grille * grille[N][N], Grille *focus);
    virtual ~Selection3_H();
};
#endif // SELECTION3_H

