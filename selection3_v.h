#ifndef SELECTION3_V
#define SELECTION3_V

#include "destroy.h"
#include "grille.h"

class Selection3_V:public Destroy
{
public:
    Selection3_V();
    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode);
    virtual void elimination(Grille * grille[N][N],Grille * clicked);
    virtual int condition(Grille * grille[N][N], Grille *focus);
    virtual ~Selection3_V();
};
#endif // SELECTION3_V

