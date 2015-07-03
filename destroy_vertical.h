#ifndef DESTROY_VERTICAL
#define DESTROY_VERTICAL
#include "destroy.h"
#include "grille.h"

class DestroyVertical:public Destroy
{
public:
    DestroyVertical();
    virtual void selection(Grille *grille[N][N],Grille *clicked,int mode);
    virtual void elimination(Grille *grille[N][N],Grille * clicked);
    virtual int condition(Grille *grille[N][N],Grille * focus);
    virtual ~DestroyVertical();
};

#endif // DESTROY_VERTICAL


