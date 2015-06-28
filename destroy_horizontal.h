#ifndef DESTROY_HORIZONTAL
#define DESTROY_HORIZONTAL

#include "destroy.h"
#include "grille.h"

class DestroyHorizontal:public Destroy
{
public:
    DestroyHorizontal();
    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode);
    virtual void elimination(Grille * grille[N][N],Grille * clicked);
    virtual int condition(Grille * grille[N][N],Grille * focus);
    virtual ~DestroyHorizontal();
};

#endif // DESTROY_HORIZONTAL

