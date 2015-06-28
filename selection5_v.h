#ifndef SELECTION5_V
#define SELECTION5_V

#include "grille.h"
#include "destroy.h"

class Selection5_V:public Destroy
{
public:
    Selection5_V();
    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode);
    virtual void elimination(Grille * grille[N][N],Grille * clicked);
    virtual int condition(Grille * grille[N][N], Grille *focus);
    virtual ~Selection5_V();
};
#endif // SELECTION5_V

