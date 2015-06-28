
#include "selection5_v.h"
#include "destroy.h"
#include "destroy_vertical.h"
#include "destroy_horizontal.h"
#include "selection_block.h"

#include "QDebug"

Selection5_V::Selection5_V()
{

}

void Selection5_V::selection(Grille * grille[10][10],Grille * clicked,int mode)
{
    int row=clicked->row;
    int col=clicked->col;
    int num=clicked->tile;
    int FiveNum[5]={0};

    switch(mode){
    case 1: // left up normal component
        clicked->tile=clicked->tile*10+3;

        if(col<=8&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))){
            grille[row][col+1]->tile=0;
        }// right one condition
        if(row<=8&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))){
            grille[row+1][col]->tile=0;
        }// down one condition

        if(grille[row][col-2]->tile/10!=0)FiveNum[0]=grille[row][col-2]->tile%10;
        if(grille[row][col-1]->tile/10!=0)FiveNum[1]=grille[row][col-1]->tile%10;
        FiveNum[2]=grille[row][col]->tile;
        if(grille[row-2][col]->tile/10!=0)FiveNum[3]=grille[row-2][col]->tile%10;
        if(grille[row-1][col]->tile/10!=0)FiveNum[4]=grille[row-1][col]->tile%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
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

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
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
    case 2: // left down normal component
        clicked->tile=clicked->tile*10+3;

        if(col<=8&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))){
            grille[row][col+1]->tile=0;
        }// right one condition
        if(row>=1&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))){
            grille[row-1][col]->tile=0;
        }// up one condition

        if(grille[row][col-2]->tile/10!=0)FiveNum[0]=grille[row][col-2]->tile%10;
        if(grille[row][col-1]->tile/10!=0)FiveNum[1]=grille[row][col-1]->tile%10;
        FiveNum[2]=grille[row][col]->tile;
        if(grille[row+1][col]->tile/10!=0)FiveNum[3]=grille[row+1][col]->tile%10;
        if(grille[row+2][col]->tile/10!=0)FiveNum[4]=grille[row+2][col]->tile%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
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

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
            case 0:
                grille[row+1+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 3: // right up normal component
        clicked->tile=clicked->tile*10+3;

        if(col>=1&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))){
            grille[row][col-1]->tile=0;
        }// left one condition
        if(row<=8&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))){
            grille[row+1][col]->tile=0;
        }// down one condition

        if(grille[row][col+1]->tile/10!=0)FiveNum[0]=grille[row][col+1]->tile%10;
        if(grille[row][col+2]->tile/10!=0)FiveNum[1]=grille[row][col+2]->tile%10;
        FiveNum[2]=grille[row][col]->tile;
        if(grille[row-2][col]->tile/10!=0)FiveNum[3]=grille[row-2][col]->tile%10;
        if(grille[row-1][col]->tile/10!=0)FiveNum[4]=grille[row-1][col]->tile%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                grille[row][col+1+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
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
    case 4: // right down normal component
        clicked->tile=clicked->tile*10+3;

        if(col>=1&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))){
            grille[row][col-1]->tile=0;
        }// left one condition
        if(row>=1&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))){
            grille[row-1][col]->tile=0;
        }// up one condition

        if(grille[row][col+1]->tile/10!=0)FiveNum[0]=grille[row][col+1]->tile%10;
        if(grille[row][col+2]->tile/10!=0)FiveNum[1]=grille[row][col+2]->tile%10;
        FiveNum[2]=grille[row][col]->tile;
        if(grille[row+1][col]->tile/10!=0)FiveNum[3]=grille[row+1][col]->tile%10;
        if(grille[row+2][col]->tile/10!=0)FiveNum[4]=grille[row+2][col]->tile%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                grille[row][col+1+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
            case 0:
                grille[row+1+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 5: // left T normal component
        clicked->tile=clicked->tile*10+3;

        if(grille[row][col-2]->tile/10!=0)FiveNum[0]=grille[row][col-2]->tile%10;
        if(grille[row][col-1]->tile/10!=0)FiveNum[1]=grille[row][col-1]->tile%10;
        if(grille[row-1][col]->tile/10!=0)FiveNum[2]=grille[row-1][col]->tile%10;
        FiveNum[3]=grille[row][col]->tile;
        if(grille[row+1][col]->tile/10!=0)FiveNum[4]=grille[row+1][col]->tile%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
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

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
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
    case 6: // right T normal component
        clicked->tile=clicked->tile*10+3;

        if(grille[row][col+1]->tile/10!=0)FiveNum[0]=grille[row][col+1]->tile%10;
        if(grille[row][col+2]->tile/10!=0)FiveNum[1]=grille[row][col+2]->tile%10;
        if(grille[row-1][col]->tile/10!=0)FiveNum[2]=grille[row-1][col]->tile%10;
        FiveNum[3]=grille[row][col]->tile;
        if(grille[row+1][col]->tile/10!=0)FiveNum[4]=grille[row+1][col]->tile%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                grille[row][col+1+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            }
        }

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
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
    case 7: // up T normal component
        clicked->tile=clicked->tile*10+3;

        if(grille[row][col-1]->tile/10!=0)FiveNum[0]=grille[row][col-1]->tile%10;
        FiveNum[1]=grille[row][col]->tile;
        if(grille[row][col+1]->tile/10!=0)FiveNum[2]=grille[row][col+1]->tile%10;
        if(grille[row-2][col]->tile/10!=0)FiveNum[3]=grille[row-2][col]->tile%10;
        if(grille[row-1][col]->tile/10!=0)FiveNum[4]=grille[row-1][col]->tile%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
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

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
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
    case 8: // down T normal component
        clicked->tile=clicked->tile*10+3;

        if(grille[row][col-1]->tile/10!=0)FiveNum[0]=grille[row][col-1]->tile%10;
        FiveNum[1]=grille[row][col]->tile;
        if(grille[row][col+1]->tile/10!=0)FiveNum[2]=grille[row][col+1]->tile%10;
        if(grille[row+1][col]->tile/10!=0)FiveNum[3]=grille[row+1][col]->tile%10;
        if(grille[row+2][col]->tile/10!=0)FiveNum[4]=grille[row+2][col]->tile%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
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

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
            case 0:
                grille[row+1+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 9: // left up special component
        num/=10;

        if(col<=8&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))){
            grille[row][col+1]->tile=0;
        }// right one condition
        if(row<=8&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))){
            grille[row+1][col]->tile=0;
        }// down one condition

        if(grille[row][col-2]->tile/10!=0)FiveNum[0]=grille[row][col-2]->tile%10;
        if(grille[row][col-1]->tile/10!=0)FiveNum[1]=grille[row][col-1]->tile%10;
        FiveNum[2]=grille[row][col]->tile%10;
        if(grille[row-2][col]->tile/10!=0)FiveNum[3]=grille[row-2][col]->tile%10;
        if(grille[row-1][col]->tile/10!=0)FiveNum[4]=grille[row-1][col]->tile%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
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

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
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
    case 10: // left down special component
        num/=10;

        if(col<=8&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))){
            grille[row][col+1]->tile=0;
        }// right one condition
        if(row>=1&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))){
            grille[row-1][col]->tile=0;
        }// up one condition

        if(grille[row][col-2]->tile/10!=0)FiveNum[0]=grille[row][col-2]->tile%10;
        if(grille[row][col-1]->tile/10!=0)FiveNum[1]=grille[row][col-1]->tile%10;
        FiveNum[2]=grille[row][col]->tile%10;
        if(grille[row+1][col]->tile/10!=0)FiveNum[3]=grille[row+1][col]->tile%10;
        if(grille[row+2][col]->tile/10!=0)FiveNum[4]=grille[row+2][col]->tile%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
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

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
            case 0:
                grille[row+1+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 11: // right up special component
        num/=10;

        if(col>=1&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))){
            grille[row][col-1]->tile=0;
        }// left one condition
        if(row<=8&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))){
            grille[row+1][col]->tile=0;
        }// down one condition

        if(grille[row][col+1]->tile/10!=0)FiveNum[0]=grille[row][col+1]->tile%10;
        if(grille[row][col+2]->tile/10!=0)FiveNum[1]=grille[row][col+2]->tile%10;
        FiveNum[2]=grille[row][col]->tile%10;
        if(grille[row-1][col]->tile/10!=0)FiveNum[3]=grille[row-1][col]->tile%10;
        if(grille[row-2][col]->tile/10!=0)FiveNum[4]=grille[row-2][col]->tile%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                grille[row][col+1+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            }
        }

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
            case 0:
                grille[row-i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row-i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row-i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row-i][col]);
                delete d;
                break;
            }
        }

        break;
    case 12: // right down special component
        num/=10;

        if(col>=1&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))){
            grille[row][col-1]->tile=0;
        }// left one condition
        if(row>=1&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))){
            grille[row-1][col]->tile=0;
        }// up one condition

        if(grille[row][col+1]->tile/10!=0)FiveNum[0]=grille[row][col+1]->tile%10;
        if(grille[row][col+2]->tile/10!=0)FiveNum[1]=grille[row][col+2]->tile%10;
        FiveNum[2]=grille[row][col]->tile%10;
        if(grille[row+1][col]->tile/10!=0)FiveNum[3]=grille[row+1][col]->tile%10;
        if(grille[row+2][col]->tile/10!=0)FiveNum[4]=grille[row+2][col]->tile%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                grille[row][col+1+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            }
        }

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
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
    case 13: // left T special component
        num/=10;

        if(grille[row][col-2]->tile/10!=0)FiveNum[0]=grille[row][col-2]->tile%10;
        if(grille[row][col-1]->tile/10!=0)FiveNum[1]=grille[row][col-1]->tile%10;
        if(grille[row-1][col]->tile/10!=0)FiveNum[2]=grille[row-1][col]->tile%10;
        FiveNum[3]=grille[row][col]->tile%10;
        if(grille[row+1][col]->tile/10!=0)FiveNum[4]=grille[row+1][col]->tile%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
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

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
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
    case 14: // right T special component
        num/=10;

        if(grille[row][col+1]->tile/10!=0)FiveNum[0]=grille[row][col+1]->tile%10;
        if(grille[row][col+2]->tile/10!=0)FiveNum[1]=grille[row][col+2]->tile%10;
        if(grille[row-1][col]->tile/10!=0)FiveNum[2]=grille[row-1][col]->tile%10;
        FiveNum[3]=grille[row][col]->tile%10;
        if(grille[row+1][col]->tile/10!=0)FiveNum[4]=grille[row+1][col]->tile%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                grille[row][col+1+i]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row][col+1+i]);
                delete d;
                break;
            }
        }

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
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
    case 15: // up T special component
        num/=10;

        if(grille[row][col-1]->tile/10!=0)FiveNum[0]=grille[row][col-1]->tile%10;
        FiveNum[1]=grille[row][col]->tile%10;
        if(grille[row][col+1]->tile/10!=0)FiveNum[2]=grille[row][col+1]->tile%10;
        if(grille[row-2][col]->tile/10!=0)FiveNum[3]=grille[row-2][col]->tile%10;
        if(grille[row-1][col]->tile/10!=0)FiveNum[4]=grille[row-1][col]->tile%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
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

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
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
    case 16: // down T special component
        num/=10;

        if(grille[row][col-1]->tile/10!=0)FiveNum[0]=grille[row][col-1]->tile%10;
        FiveNum[1]=grille[row][col]->tile%10;
        if(grille[row][col+1]->tile/10!=0)FiveNum[2]=grille[row][col+1]->tile%10;
        if(grille[row+1][col]->tile/10!=0)FiveNum[3]=grille[row+1][col]->tile%10;
        if(grille[row+2][col]->tile/10!=0)FiveNum[4]=grille[row+2][col]->tile%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
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

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
            case 0:
                grille[row+1+i][col]->tile=0;
                break;
            case 1:
                d=new DestroyVertical;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            case 2:
                d=new DestroyHorizontal;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            case 3:
                d=new Selection_block;
                d->elimination(grille,grille[row+1+i][col]);
                delete d;
                break;
            }
        }

        break;
    default:
        qDebug()<<"Selection5_V error";
    }
}

void Selection5_V::elimination(Grille *grille[10][10],Grille * clicked)
{
    // garbage function
}

int Selection5_V::condition(Grille *grille[10][10], Grille *focus)
{
    int row=focus->row;
    int col=focus->col;
    int num=focus->tile;
    if(num!=0&&num!=5){
        if(num/10==0){ // control normal component
            if(row>=2&&col>=2&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/10))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/10))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))){
                return 1;
            }// left up condition
            if(row<=7&&col>=2&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/10))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/10))){
                return 2;
            }// left down condition
            if(row>=2&&col<=7&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/10))&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/10))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))){
                return 3;
            }// right up condition
            if(row<=7&&col<=7&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/10))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/10))){
                return 4;
            }// right down condition
            if(col>=2&&row>=1&&row<=8&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/10))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))){
                return 5;
            }// left T condition
            if(col<=7&&row>=1&&row<=8&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/10))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))){
                return 6;
            }// right T condition
            if(row>=2&&col>=1&&col<=8&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/10))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))){
                return 7;
            }// up T condition
            if(row<=7&&col>=1&&col<=8&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/10))){
                return 8;
            }// down T condition
        }
        else if(num/10!=0){ // control special component
            num/=10;
            if(row>=2&&col>=2&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/10))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/10))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))){
                return 9;
            }// left up condition
            if(row<=7&&col>=2&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/10))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/10))){
                return 10;
            }// left down condition
            if(row>=2&&col<=7&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/10))&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/10))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))){
                return 11;
            }// right up condition
            if(row<=7&&col<=7&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/10))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/10))){
                return 12;
            }// right down condition
            if(col>=2&&row>=1&&row<=8&&((num==grille[row][col-2]->tile)||(num==grille[row][col-2]->tile/10))&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))){
                return 13;
            }// left T condition
            if(col<=7&&row>=1&&row<=8&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))&&((num==grille[row][col+2]->tile)||(num==grille[row][col+2]->tile/10))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))){
                return 14;
            }// right T condition
            if(row>=2&&col>=1&&col<=8&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))&&((num==grille[row-2][col]->tile)||(num==grille[row-2][col]->tile/10))&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/10))){
                return 15;
            }// up T condition
            if(row<=7&&col>=1&&col<=8&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/10))&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/10))&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/10))&&((num==grille[row+2][col]->tile)||(num==grille[row+2][col]->tile/10))){
                return 16;
            }// down T condition

        }
    }
    return 0;
}

Selection5_V::~Selection5_V()
{

}

