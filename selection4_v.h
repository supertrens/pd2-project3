#ifndef SELECTION4_V
#define SELECTION4_V

#include "destroy.h"
#include "grille.h"

class Selection4_V:public Destroy
{
public:
    Selection4_V();
    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode);
    virtual void elimination(Grille * grille[N][N],Grille * clicked);
    virtual int condition(Grille * grille[N][N], Grille *focus);
    virtual ~Selection4_V();
};

#endif // SELECTION4_V

