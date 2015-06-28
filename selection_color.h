#ifndef SELECTION_COLOR
#define SELECTION_COLOR

#include "grille.h"
#include "destroy.h"

class Selection_Color:public Destroy
{
public:
    Selection_Color();

    virtual void selection(Grille * grille[N][N],Grille * clicked,int mode);
    virtual void elimination(Grille * grille[N][N],Grille * clicked);
    virtual int condition(Grille * grille[N][N], Grille *focus);
    virtual ~Selection_Color();
};
#endif // SELECTION_COLOR

