#ifndef SELECTION4_H
#define SELECTION4_H

#include "destroy.h"
#include "grille.h"

class Selection4_H:public Destroy
{
public:
    Selection4_H();
    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode);
    virtual void elimination(Grille * grille[N][N],Grille * clicked);
    virtual int condition(Grille * grille[N][N], Grille *focus);
    virtual ~Selection4_H();
};

#endif // SELECTION4_H

