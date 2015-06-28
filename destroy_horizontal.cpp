#include "destroy_horizontal.h"
#include "destroy.h"
#include "destroy_vertical.h"
#include "selection_block.h"
#define N 10

#include <QDebug>

DestroyHorizontal::DestroyHorizontal()
{

}

void DestroyHorizontal::selection(Grille * grille[N][N],Grille * clicked,int mode)
{
    // garbage function
}

void DestroyHorizontal::elimination(Grille *grille[N][N], Grille *clicked)
{
    clicked->tile=0;
    int row=clicked->row;
    Destroy * d;
    int TenNum[N]={0};

    for(int i=0;i<N;i++){
        if(grille[row][i]->tile/N!=0){
            TenNum[i]=grille[row][i]->tile%N;
        }
        grille[row][i]->tile=0; // reinitialize to zero (avoid infinite loop)
    }

    for(int i=0;i<N;i++){
        switch(TenNum[i]){
        case 0: // normal component
        break;
        case 1: // vertical bomb
            d=new DestroyVertical;
            d->elimination(grille,grille[row][i]);
            delete d;
            break;
        case 2: // DestroyHorizontal bomb
            d=new DestroyHorizontal;
            d->elimination(grille,grille[row][i]);
            delete d;
            break;
        case 3: // bomb
            d = new Selection_block;
            d->elimination(grille,grille[row][i]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy DestroyHorizontal line error";
        }
    }
}

int DestroyHorizontal::condition(Grille *grille[N][N], Grille *focus)
{
    // garbage function
    return 0;
}

DestroyHorizontal::~DestroyHorizontal()
{

}


