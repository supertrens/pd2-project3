
#include "selection4_H.h"
#include "destroy.h"
#include "destroy_Vertical.h"
#include "destroy_Horizontal.h"
#include "selection_block.h"

#include <QDebug>

Selection4_H::Selection4_H()
{

}

void Selection4_H::selection(Grille * grille[N][N],Grille * clicked,int mode)
{
    int row=clicked->row;
    int col=clicked->col;
    int FourNum[4]={0};
    Destroy * d;

    switch(mode){
    case 1:// OXOO normal component
        clicked->tile=clicked->tile*N+2;

        if(grille[row][col-1]->tile/N!=0)FourNum[0]=grille[row][col-1]->tile%N;
        FourNum[1]=grille[row][col]->tile;
        if(grille[row][col+1]->tile/N!=0)FourNum[2]=grille[row][col+1]->tile%N;
        if(grille[row][col+2]->tile/N!=0)FourNum[3]=grille[row][col+2]->tile%N;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                grille[row][col-1+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col-1+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col-1+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col-1+i]);
                delete d;
                break;
            }
        }

        break;
    case 2:// OOXO normal component
        clicked->tile=clicked->tile*N+2;

        if(grille[row][col-2]->tile/N!=0)FourNum[0]=grille[row][col-2]->tile%N;
        if(grille[row][col-1]->tile/N!=0)FourNum[1]=grille[row][col-1]->tile%N;
        FourNum[2]=grille[row][col]->tile;
        if(grille[row][col+1]->tile/N!=0)FourNum[3]=grille[row][col+1]->tile%N;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                grille[row][col-2+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col-2+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col-2+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col-2+i]);
                delete d;
                break;
            }
        }

        break;
    case 3:// OXOO special component

        if(grille[row][col-1]->tile/N!=0)FourNum[0]=grille[row][col-1]->tile%N;
        FourNum[1]=grille[row][col]->tile%N;
        if(grille[row][col+1]->tile/N!=0)FourNum[2]=grille[row][col+1]->tile%N;
        if(grille[row][col+2]->tile/N!=0)FourNum[3]=grille[row][col+2]->tile%N;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                grille[row][col-1+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col-1+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col-1+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col-1+i]);
                delete d;
                break;
            }
        }

        break;
    case 4:// OOXO special component

        if(grille[row][col-2]->tile/N!=0)FourNum[0]=grille[row][col-2]->tile%N;
        if(grille[row][col-1]->tile/N!=0)FourNum[1]=grille[row][col-1]->tile%N;
        FourNum[2]=grille[row][col]->tile%N;
        if(grille[row][col+1]->tile/N!=0)FourNum[3]=grille[row][col+1]->tile%N;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                grille[row][col-2+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col-2+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col-2+i]);
                delete d;
                break;
            case 3:
                d = new Selection_block;
                d->elimination(grille,grille[row][col-2+i]);
                delete d;
                break;
            }
        }

        break;
    default:
        qDebug()<<"Spawn horizontal bomb error";
    }
}

void Selection4_H::elimination(Grille *grille[N][N],Grille * clicked)
{
    // garbage function
}

int Selection4_H::condition(Grille *grille[N][N], Grille *focus)
{
    int row=focus->row;
    int col=focus->col;
    int num=focus->tile;
    if(num!=0&&num!=5){
        if(num/N==0){ // control normal component
            // OXOO condition
            if(col>=1&&col<=7&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/N))){
            return 1;
            }

            // OOXO condition
            if(col>=2&&col<=8&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/N))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))){
                return 2;
            }
        }
        else if(num/N!=0){ // control special component
            num/=N;
            // OXOO condition
            if(col>=1&&col<=7&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/N))){
            return 3;
            }

            // OOXO condition
            if(col>=2&&col<=8&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/N))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))){
                return 4;
            }
        }
    }
    return 0;
}

Selection4_H::~Selection4_H()
{

}

