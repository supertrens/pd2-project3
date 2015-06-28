
#include "selection_block.h"
#include "destroy.h"
#include "destroy_Horizontal.h"
#include "destroy_Vertical.h"


#include<QDebug>

Selection_block::Selection_block()
{

}

void Selection_block::selection(Grille * grille[N][N],Grille * clicked,int mode)
{
    // garbage function
}

void Selection_block::elimination(Grille *grille[N][N], Grille *clicked)
{
    clicked->tile=0;
    int row=clicked->row;
    int col=clicked->col;
    Destroy * d;
    int EightNum[8]={0};

    // find special component
    if(row-1>=0&&col-1>=0&&grille[row-1][col-1]->tile/N!=0){  EightNum[0]=grille[row-1][col-1]->tile%N;}
    if(row-1>=0&&grille[row-1][col]->tile/N!=0){              EightNum[1]=grille[row-1][col]->tile%N;}
    if(row-1>=0&&col+1<=9&&grille[row-1][col+1]->tile/N!=0){  EightNum[2]=grille[row-1][col+1]->tile%N;}
    if(col-1>=0&&grille[row][col-1]->tile/N!=0){              EightNum[3]=grille[row][col-1]->tile%N;}
    if(col+1<=9&&grille[row][col+1]->tile/N!=0){              EightNum[4]=grille[row][col+1]->tile%N;}
    if(row+1<=9&&col-1>=0&&grille[row+1][col-1]->tile/N!=0){  EightNum[5]=grille[row+1][col-1]->tile%N;}
    if(row+1<=9&&grille[row+1][col]->tile/N!=0){              EightNum[6]=grille[row+1][col]->tile%N;}
    if(row+1<=9&&col+1<=9&&grille[row+1][col+1]->tile/N!=0){  EightNum[7]=grille[row+1][col+1]->tile%N;}

    // reinitialize to zero (avoid infinite loop)
    if(row-1>=0&&col-1>=0){  grille[row-1][col-1]->tile=0;}
    if(row-1>=0){            grille[row-1][col]->tile=0;}
    if(row-1>=0&&col+1<=9){  grille[row-1][col+1]->tile=0;}
    if(col-1>=0){            grille[row][col-1]->tile=0;}
    if(col+1<=9){            grille[row][col+1]->tile=0;}
    if(row+1<=9&&col-1>=0){  grille[row+1][col-1]->tile=0;}
    if(row+1<=9){            grille[row+1][col]->tile=0;}
    if(row+1<=9&&col+1<=9){  grille[row+1][col+1]->tile=0;}

    if(row-1>=0&&col-1>=0){
        switch(EightNum[0]){
        case 0: // normal component
        break;
        case 1: // DestroyVertical bomb
            d=new DestroyVertical;
            d->elimination(grille,grille[row-1][col-1]);
            delete d;
            break;
        case 2: // DestroyDestroyHorizontal bomb
            d=new DestroyHorizontal;
            d->elimination(grille,grille[row-1][col-1]);
            delete d;
            break;
        case 3: // bomb
            d=new Selection_block;
            d->elimination(grille,grille[row-1][col-1]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy selection_block error";
        }
    }

    if(row-1>=0){
        switch(EightNum[1]){
        case 0: // normal component
        break;
        case 1: // DestroyVertical bomb
            d=new DestroyVertical;
            d->elimination(grille,grille[row-1][col]);
            delete d;
            break;
        case 2: // DestroyHorizontal bomb
            d=new DestroyHorizontal;
            d->elimination(grille,grille[row-1][col]);
            delete d;
            break;
        case 3: // bomb
            d=new Selection_block;
            d->elimination(grille,grille[row-1][col]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy selection_block error";
        }
    }

    if(row-1>=0&&col+1<=9){
        switch(EightNum[2]){
        case 0: // normal component
        break;
        case 1: // DestroyVertical bomb
            d=new DestroyVertical;
            d->elimination(grille,grille[row-1][col+1]);
            delete d;
            break;
        case 2: // DestroyHorizontal bomb
            d=new DestroyHorizontal;
            d->elimination(grille,grille[row-1][col+1]);
            delete d;
            break;
        case 3: // bomb
            d=new Selection_block;
            d->elimination(grille,grille[row-1][col+1]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(col-1>=0){
        switch(EightNum[3]){
        case 0: // normal component
        break;
        case 1: // DestroyVertical bomb
            d=new DestroyVertical;
            d->elimination(grille,grille[row][col-1]);
            delete d;
            break;
        case 2: // DestroyHorizontal bomb
            d=new DestroyHorizontal;
            d->elimination(grille,grille[row][col-1]);
            delete d;
            break;
        case 3: // bomb
            d=new Selection_block;
            d->elimination(grille,grille[row][col-1]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(col+1<=9){
        switch(EightNum[4]){
        case 0: // normal component
        break;
        case 1: // DestroyVertical bomb
            d=new DestroyVertical;
            d->elimination(grille,grille[row][col+1]);
            delete d;
            break;
        case 2: // DestroyHorizontal bomb
            d=new DestroyHorizontal;
            d->elimination(grille,grille[row][col+1]);
            delete d;
            break;
        case 3: // bomb
            d=new Selection_block;
            d->elimination(grille,grille[row][col+1]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(row+1<=9&&col-1>=0){
        switch(EightNum[5]){
        case 0: // normal component
        break;
        case 1: // DestroyVertical bomb
            d=new DestroyVertical;
            d->elimination(grille,grille[row+1][col-1]);
            delete d;
            break;
        case 2: // DestroyHorizontal bomb
            d=new DestroyHorizontal;
            d->elimination(grille,grille[row+1][col-1]);
            delete d;
            break;
        case 3: // bomb
            d=new Selection_block;
            d->elimination(grille,grille[row+1][col-1]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(row+1<=9){
        switch(EightNum[6]){
        case 0: // normal component
        break;
        case 1: // DestroyVertical bomb
            d=new DestroyVertical;
            d->elimination(grille,grille[row+1][col]);
            delete d;
            break;
        case 2: // DestroyHorizontal bomb
            d=new DestroyHorizontal;
            d->elimination(grille,grille[row+1][col]);
            delete d;
            break;
        case 3: // bomb
            d=new Selection_block;
            d->elimination(grille,grille[row+1][col]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(row+1<=9&&col+1<=9){
        switch(EightNum[7]){
        case 0: // normal component
        break;
        case 1: // DestroyVertical bomb
            d=new DestroyVertical;
            d->elimination(grille,grille[row+1][col+1]);
            delete d;
            break;
        case 2: // DestroyHorizontal bomb
            d=new DestroyHorizontal;
            d->elimination(grille,grille[row+1][col+1]);
            delete d;
            break;
        case 3: // bomb
            d=new Selection_block;
            d->elimination(grille,grille[row+1][col+1]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }
}

int Selection_block::condition(Grille *grille[N][N], Grille *focus)
{
    // garbage function
    return 0;
}

Selection_block::~Selection_block()
{

}

