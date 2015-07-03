
#include "selection5_v.h"
#include "destroy.h"
#include "destroy_vertical.h"
#include "destroy_horizontal.h"
#include "selection_block.h"

#include "QDebug"

Selection5_V::Selection5_V()
{

}

void Selection5_V::selection(Grille *grille[N][N], Grille *clicked, int mode)
{
    int row=clicked->row;
    int col=clicked->col;
    int num=clicked->tile;
    int FiveNum[5]={0};

    switch(mode)
    {
    case 1:// vertical normal component
        clicked->tile=5;
        if(col>=2&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/N))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))){
            grille[row][col-2]->tile=0;
            grille[row][col-1]->tile=0;
        }// left condition
        if(col<=7&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/N))){
            grille[row][col+1]->tile=0;
            grille[row][col+2]->tile=0;
        }// right condition

        if(grille[row-2][col]->tile/N!=0)FiveNum[0]=grille[row-2][col]->tile%N;
        if(grille[row-1][col]->tile/N!=0)FiveNum[1]=grille[row-1][col]->tile%N;
        FiveNum[2]=grille[row][col]->tile;
        if(grille[row+1][col]->tile/N!=0)FiveNum[3]=grille[row+1][col]->tile%N;
        if(grille[row+2][col]->tile/N!=0)FiveNum[4]=grille[row+2][col]->tile%N;

        for(int i=0;i<5;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                grille[row-2+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination (grille,grille[row-2+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination (grille,grille[row-2+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination (grille,grille[row-2+i][col]);
                delete d;
                break;
            }
        }
        break;
    case 2:// horizontal normal component
        clicked->tile=5;
        if(row>=2&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/N))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))){
            grille[row-2][col]->tile=0;
            grille[row-1][col]->tile=0;
        }// up condition
        if(row<=7&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/N))){
            grille[row-2][col]->tile=0;
            grille[row-1][col]->tile=0;
        }// down condition

        if(grille[row][col-2]->tile/N!=0)FiveNum[0]=grille[row][col-2]->tile%N;
        if(grille[row][col-1]->tile/N!=0)FiveNum[1]=grille[row][col-1]->tile%N;
        FiveNum[2]=grille[row][col]->tile;
        if(grille[row][col+1]->tile/N!=0)FiveNum[3]=grille[row][col+1]->tile%N;
        if(grille[row][col+2]->tile/N!=0)FiveNum[4]=grille[row][col+2]->tile%N;

        for(int i=0;i<5;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                grille[row][col-2+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination (grille,grille[row][col-2+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination (grille,grille[row][col-2+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination (grille,grille[row][col-2+i]);
                delete d;
                break;
            }
        }
        break;
    case 3:// DestroyVertical special component
        num/=N;
        if(col>=2&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/N))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))){
            grille[row][col-2]->tile=0;
            grille[row][col-1]->tile=0;
        }// left condition
        if(col<=7&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/N))){
            grille[row][col+1]->tile=0;
            grille[row][col+2]->tile=0;
        }// right condition

        if(grille[row-2][col]->tile/N!=0)FiveNum[0]=grille[row-2][col]->tile%N;
        if(grille[row-1][col]->tile/N!=0)FiveNum[1]=grille[row-1][col]->tile%N;
        FiveNum[2]=grille[row][col]->tile%N;
        if(grille[row+1][col]->tile/N!=0)FiveNum[3]=grille[row+1][col]->tile%N;
        if(grille[row+2][col]->tile/N!=0)FiveNum[4]=grille[row+2][col]->tile%N;

        for(int i=0;i<5;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                grille[row-2+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination (grille,grille[row-2+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination (grille,grille[row-2+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination (grille,grille[row-2+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 4:// DestroyHorizontal special component
        num/=N;
        if(row>=2&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/N))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))){
            grille[row-2][col]->tile=0;
            grille[row-1][col]->tile=0;
        }// up condition
        if(row<=7&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/N))){
            grille[row-2][col]->tile=0;
            grille[row-1][col]->tile=0;
        }// down condition

        if(grille[row][col-2]->tile/N!=0)FiveNum[0]=grille[row][col-2]->tile%N;
        if(grille[row][col-1]->tile/N!=0)FiveNum[1]=grille[row][col-1]->tile%N;
        FiveNum[2]=grille[row][col]->tile%N;
        if(grille[row][col+1]->tile/N!=0)FiveNum[3]=grille[row][col+1]->tile%N;
        if(grille[row][col+2]->tile/N!=0)FiveNum[4]=grille[row][col+2]->tile%N;

        for(int i=0;i<5;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                grille[row][col-2+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination (grille,grille[row][col-2+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination (grille,grille[row][col-2+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination (grille,grille[row][col-2+i]);
                delete d;
                break;
            }
        }

        break;
    default:
        qDebug()<<"spawn 5 error";
    }

}


void Selection5_V::elimination(Grille *grille[10][10],Grille * focus)
{
    // garbage function
}

int Selection5_V::condition(Grille *grille[10][10], Grille *focus)
{
    int row= focus->row;
    int col= focus->col;
    int num= focus->tile;

    if (num!=0 && num!=5)
    {
        if (num/10==0)
        {
            if (row>=2 && row<=7 && ((num==grille[row-2][col]->tile) || (num==grille[row-2][col]->tile/10)) && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/10)) && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/10)) && ((num==grille[row+2][col]->tile) || (num==grille[row+2][col]->tile/10)))
            {return 1;}//vertical without bomb

            if (col>=2 && col<=7 && ((num==grille[row][col-2]->tile) || (num==grille[row][col-2]->tile/10)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/10)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/10)) && ((num==grille[row][col+2]->tile) || (num==grille[row][col+2]->tile/10)))
            {return 2;}//horizontal without bomb

        }
        else
        {
            num/=10;//determine the color
            if (row>=2 && row<=7 && ((num==grille[row-2][col]->tile) || (num==grille[row-2][col]->tile/10)) && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/10)) && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/10)) && ((num==grille[row+2][col]->tile) || (num==grille[row+2][col]->tile/10)))
            {return 3;}//vertical with bomb

            if (col>=2 && col<=7 && ((num==grille[row][col-2]->tile) || (num==grille[row][col-2]->tile/10)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/10)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/10)) && ((num==grille[row][col+2]->tile) || (num==grille[row][col+2]->tile/10)))
            {return 4;}//horizontal with bomb

        }
    }
    return 0;
}

Selection5_V::~Selection5_V()
{

}

