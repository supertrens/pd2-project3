#include "selection3_v.h"
#include "destroy.h"
#include "destroy_horizontal.h"
#include "destroy_vertical.h"
#include "selection_block.h"

#include <QDebug>

Selection3_V::Selection3_V()
{

}

void Selection3_V::selection(Grille * grille[N][N],Grille * clicked,int mode)
{
    int row=clicked->row;
    int col=clicked->col;
    Destroy * d;
    int ThreeNum[3]={0};

    switch(mode){
    case 1: // topest normal component
        clicked->tile=0;

        ThreeNum[0]=grille[row][col]->tile;
        if(grille[row+1][col]->tile/N!=0)ThreeNum[1]=grille[row+1][col]->tile%N;
        if(grille[row+2][col]->tile/N!=0)ThreeNum[2]=grille[row+2][col]->tile%N;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                grille[row+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 2: // middle normal component
        clicked->tile=0;

        if(grille[row-1][col]->tile/N!=0)ThreeNum[0]=grille
                [row-1][col]->tile%N;
        ThreeNum[1]=grille[row][col]->tile;
        if(grille[row+1][col]->tile/N!=0)ThreeNum[2]=grille[row+1][col]->tile%N;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                grille[row-1+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row-1+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row-1+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row-1+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 3: // downest normal component
        clicked->tile=0;

        if(grille[row-2][col]->tile/N!=0)ThreeNum[0]=grille[row-2][col]->tile%N;
        if(grille[row-1][col]->tile/N!=0)ThreeNum[1]=grille[row-1][col]->tile%N;
        ThreeNum[2]=grille[row][col]->tile;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                grille[row-2+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row-2+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row-2+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row-2+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 4: // topest special component

        ThreeNum[0]=grille[row][col]->tile%N;
        if(grille[row+1][col]->tile/N!=0)ThreeNum[1]=grille[row+1][col]->tile%N;
        if(grille[row+2][col]->tile/N!=0)ThreeNum[2]=grille[row+2][col]->tile%N;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                grille[row+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row+i][col]);
                delete d;
                break;
            }
        }
        break;
    case 5: // middle special component

        if(grille[row-1][col]->tile/N!=0)ThreeNum[0]=grille[row-1][col]->tile%N;
        ThreeNum[1]=grille[row][col]->tile%N;
        if(grille[row+1][col]->tile/N!=0)ThreeNum[2]=grille[row+1][col]->tile%N;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                grille[row-1+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row-1+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row-1+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row-1+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 6: // downest special component

        if(grille[row-2][col]->tile/N!=0)ThreeNum[0]=grille[row-2][col]->tile%N;
        if(grille[row-1][col]->tile/N!=0)ThreeNum[1]=grille[row-1][col]->tile%N;
        ThreeNum[2]=grille[row][col]->tile%N;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                grille[row-2+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row-2+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row-2+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row-2+i][col]);
                delete d;
                break;
            }
        }

        break;
    }
}

void Selection3_V::elimination(Grille *grille[N][N], Grille *clicked)
{
    // garbage function
}

int Selection3_V::condition(Grille *grille[N][N], Grille *focus)
{
    int row=focus->row;
    int col=focus->col;
    int num=focus->tile;
    if(num!=0&&num!=5){
        if(num/N==0){ // control normal component
            // topest condition
            if(row<=7&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/N))){
                return 1;
            }

            // moddle condition
            if(row>=1&&row<=8&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))){
                return 2;
            }

            // downest condition
            if(row>=2&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/N))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))){
                return 3;
            }
        }
        else if(num/N!=0){ // control special component
            num/=N;
            // topest condition
            if(row<=7&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/N))){
                return 4;
            }

            // moddle condition
            if(row>=1&&row<=8&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))){
                return 5;
            }

            // downest condition
            if(row>=2&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/N))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))){
                return 6;
            }
        }
    }
    return 0;
}

Selection3_V::~Selection3_V()
{

}


