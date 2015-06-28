#ifndef SELECTION_BLOCK
#define SELECTION_BLOCK

#include "grille.h"
#include "destroy.h"
class Selection_block:public Destroy
{
public:
    Selection_block();
    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode);
    virtual void elimination(Grille * grille[N][N],Grille * clicked);
    virtual int condition(Grille * grille[N][N], Grille *focus);
    virtual ~Selection_block();
};

#endif // SELECTION_BLOCK

