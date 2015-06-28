#ifndef SELECTION5_H
#define SELECTION5_H

#include "grille.h"
#include "destroy.h"

class Selection5_H:public Destroy
{
public:
    Selection5_H();
    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode);
    virtual void elimination(Grille * grille[N][N],Grille * clicked);
    virtual int condition(Grille * grille[N][N], Grille *focus);
    virtual ~Selection5_H();
};
#endif // SELECTION5_H

