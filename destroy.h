#ifndef DESTROY_H
#define DESTROY_H
#include "grille.h"

#define N 10
class Destroy
{
public:
    Destroy();
    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode)=0;
    virtual void elimination(Grille * grille[N][N],Grille * clicked)=0;
    virtual int condition(Grille * grille[N][N],Grille * focus)=0;
    virtual ~Destroy();
};

#endif // DESTROY_H

