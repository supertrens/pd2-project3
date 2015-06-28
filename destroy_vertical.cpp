#include "destroy_vertical.h"
#include "destroy.h"
#include "destroy_horizontal.h"
#include "selection_block.h"

#include <QDebug>

DestroyVertical::DestroyVertical()
{
}

void DestroyVertical::selection(Grille *grille[N][N],Grille * clicked,int mode)
{
    // garbage function
}

void DestroyVertical::elimination(Grille *grille[N][N], Grille *clicked)
{
    clicked->tile=0;
    int col=clicked->col;
    Destroy * d;
    int TenNum[N]={0};

    for(int i=0;i<N;i++){
        if(grille[i][col]->tile/N!=0){
            TenNum[i]=grille[i][col]->tile%N;
        }
        grille[i][col]->tile=0; // reinitialize to zero (avoid infinite loop)
    }

    for(int i=0;i<N;i++){
        switch(TenNum[i]){
        case 0: // normal component
        break;
        case 1: // vertical bomb
            d=new DestroyVertical;
            d->elimination(grille,grille[i][col]);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new DestroyHorizontal;
            d->elimination(grille,grille[i][col]);
            delete d;
            break;
        case 3: // bomb
            d=new Selection_block;
            d->elimination(grille,grille[i][col]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy horizontal line error";
        }
    }
}

int DestroyVertical::condition(Grille *grille[N][N], Grille *focus)
{
    // garbage function
    return 0;
}

DestroyVertical::~DestroyVertical()
{

}


