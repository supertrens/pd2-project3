#ifndef CENTRAL_H
#define CENTRAL_H
#include "grille.h"
#include "destroy.h"

class Central:public Destroy
{
public:
    Central ();
    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode);
    virtual void elimination(Grille * grille[N][N],Grille * clicked);
    virtual int condition(Grille *grille[N][N], Grille *focus);
    virtual ~Central();
};


#endif // CENTRAL_H

