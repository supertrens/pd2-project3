
#include "Selection4_V.h"
#include <QDebug>
#include "destroy.h"
#include "destroy_vertical.h"
#include "destroy_horizontal.h"
#include "selection_block.h"

Selection4_V::Selection4_V()
{

}

void Selection4_V::selection(Grille *grille[N][N],Grille * clicked,int mode)
{
    int row =clicked->row;
    int col =clicked->col;
    int num =clicked->tile;
    int FourNum[4]={0};
    Destroy * d;

    switch(mode){
    case 1: // O normal component
            // X
            // O
            // O

        clicked->tile=clicked->tile*N+1;

        if(grille[row-1][col]->tile/N!=0)FourNum[0]=grille[row-1][col]->tile%N;
        FourNum[1]=grille[row][col]->tile;
        if(grille[row+1][col]->tile/N!=0)FourNum[2]=grille[row+1][col]->tile%N;
        if(grille[row+2][col]->tile/N!=0)FourNum[3]=grille[row+2][col]->tile%N;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
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
    case 2: // O normal component
            // O
            // X
            // O

        clicked->tile=clicked->tile*N+1;

        if(grille[row-2][col]->tile/N!=0)FourNum[0]=grille[row-2][col]->tile%N;
        if(grille[row-1][col]->tile/N!=0)FourNum[1]=grille[row-1][col]->tile%N;
        FourNum[2]=grille[row][col]->tile;
        if(grille[row+1][col]->tile/N!=0)FourNum[3]=grille[row+1][col]->tile%N;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
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
    case 3: // O special component
            // X
            // O
            // O

        if(grille[row-1][col]->tile/N!=0)FourNum[0]=grille[row-1][col]->tile%N;
        FourNum[1]=grille[row][col]->tile%N;
        if(grille[row+1][col]->tile/N!=0)FourNum[2]=grille[row+1][col]->tile%N;
        if(grille[row+2][col]->tile/N!=0)FourNum[3]=grille[row+2][col]->tile%N;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
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
    case 4: // O special component
            // O
            // X
            // O

        if(grille[row-2][col]->tile/N!=0)FourNum[0]=grille[row-2][col]->tile%N;
        if(grille[row-1][col]->tile/N!=0)FourNum[1]=grille[row-1][col]->tile%N;
        FourNum[2]=grille[row][col]->tile%N;
        if(grille[row+1][col]->tile/N!=0)FourNum[3]=grille[row+1][col]->tile%N;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
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
    default:
        qDebug()<<"Spawn horizontal bomb error";
    }
}

void Selection4_V::elimination(Grille *grille[N][N],Grille * clicked)
{
    // garbage function
}

int Selection4_V::condition(Grille *grille[N][N], Grille *focus)
{
    int row=focus->row;
    int col=focus->col;
    int num=focus->tile;
    if(num!=0&&num!=5){
        if(num/N==0){ // control normal component
            // O
            // X
            // O
            // O condition
            if(row>=1&&row<=7&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/N))){
                return 1;
            }

            // O
            // O
            // X
            // O condition
            if(row>=2&&row<=8&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/N))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))){
                return 2;
            }
        }
        else if(num/N!=0){ // control special component
            num/=N;
            // O
            // X
            // O
            // O condition
            if(row>=1&&row<=7&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/N))){
                return 3;
            }

            // O
            // O
            // X
            // O condition
            if(row>=2&&row<=8&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/N))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))){
                return 4;
            }
        }
    }
    return 0;
}

Selection4_V::~Selection4_V()
{

}

