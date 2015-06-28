
#include "selection3_h.h"
#include "destroy.h"
#include "destroy_horizontal.h"
#include "destroy_vertical.h"
#include "selection_block.h"

#include "QDebug"

Selection3_H::Selection3_H()
{

}

void Selection3_H::selection(Grille * grille[N][N],Grille * clicked,int mode)
{
    int row=clicked->row;
    int col=clicked->col;
    Destroy * d;
    int ThreeNum[3]={0};

    switch(mode){
    case 1: // leftest normal component
        clicked->tile=0;

        ThreeNum[0]=grille[row][col]->tile;
        if(grille[row][col+1]->tile/N!=0)ThreeNum[1]=grille[row][col+1]->tile%N;
        if(grille[row][col+2]->tile/N!=0)ThreeNum[2]=grille[row][col+2]->tile%N;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                grille  [row][col+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille  ,grille[row][col+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col+i]);
                delete d;
                break;
            }
        }

        break;
    case 2: // middle normal component
        clicked->tile=0;

        if(grille[row][col-1]->tile/N!=0)ThreeNum[0]=grille[row][col-1]->tile%N;
        ThreeNum[1]=grille[row][col]->tile;
        if(grille[row][col+1]->tile/N!=0)ThreeNum[2]=grille[row][col+1]->tile%N;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 3: // rightest normal component
        clicked->tile=0;

        if(grille[row][col-2]->tile/N!=0)ThreeNum[0]=grille[row][col-2]->tile%N;
        if(grille[row][col-1]->tile/N!=0)ThreeNum[1]=grille[row][col-1]->tile%N;
        ThreeNum[2]=grille[row][col]->tile;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 4: // leftest normal component

        ThreeNum[0]=grille[row][col]->tile%N;
        if(grille[row][col+1]->tile/N!=0)ThreeNum[1]=grille[row][col+1]->tile%N;
        if(grille[row][col+2]->tile/N!=0)ThreeNum[2]=grille[row][col+2]->tile%N;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                grille[row][col+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col+i]);
                delete d;
                break;
            }
        }

        break;
    case 5: // middle normal component

        if(grille[row][col-1]->tile/N!=0)ThreeNum[0]=grille[row][col-1]->tile%N;
        ThreeNum[1]=grille[row][col]->tile%N;
        if(grille[row][col+1]->tile/N!=0)ThreeNum[2]=grille[row][col+1]->tile%N;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 6: // rightest normal component

        if(grille[row][col-2]->tile/N!=0)ThreeNum[0]=grille[row][col-2]->tile%N;
        if(grille[row][col-1]->tile/N!=0)ThreeNum[1]=grille[row][col-1]->tile%N;
        ThreeNum[2]=grille[row][col]->tile%N;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    }
}

void Selection3_H::elimination(Grille *grille[N][N], Grille *clicked)
{
    // garbage function
}

int Selection3_H::condition(Grille *grille[N][N], Grille *focus)
{
    int row=focus->row;
    int col=focus->col;
    int num=focus->tile;
    if(num!=0&&num!=5){
        if(num/N==0){ // control normal component
            // leftest condition
            if(col<=7&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/N))){
                return 1;
            }

            // moddle condition
            if(col>=1&&col<=8&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))){
                return 2;
            }

            // rightest condition
            if(col>=2&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/N))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))){
                return 3;
            }
        }
        else if(num/N!=0){ // control special component
            num/=N;
            // leftest condition
            if(col<=7&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/N))){
                return 4;
            }

            // moddle condition
            if(col>=1&&col<=8&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))){
                return 5;
            }

            // rightest condition
            if(col>=2&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/N))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))){
                return 6;
            }
        }
    }
    return 0;
}

Selection3_H::~Selection3_H()
{

}

