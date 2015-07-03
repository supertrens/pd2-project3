
#include "selection_block.h"
#include "destroy.h"
#include "destroy_Horizontal.h"
#include "destroy_Vertical.h"


#include<QDebug>

Selection_block::Selection_block()
{


}

void Selection_block::selection(Grille * grille[N][N],Grille * focus,int mode)
{
        int row=focus->row;
        int col=focus->col;
        int num=focus->tile;
        int FiveNum[5]={0};

        switch(mode){
        case 1: // left up normal component
            focus->tile=focus->tile*N+3;

            if(col<=8&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))){
                grille[row][col+1]->tile=0;
            }// right one condition
            if(row<=8&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))){
                grille[row+1][col]->tile=0;
            }// down one condition

            if(grille[row][col-2]->tile/N!=0)FiveNum[0]=grille[row][col-2]->tile%N;
            if(grille[row][col-1]->tile/N!=0)FiveNum[1]=grille[row][col-1]->tile%N;
            FiveNum[2]=grille[row][col]->tile;
            if(grille[row-2][col]->tile/N!=0)FiveNum[3]=grille[row-2][col]->tile%N;
            if(grille[row-1][col]->tile/N!=0)FiveNum[4]=grille[row-1][col]->tile%N;

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
            focus->tile=focus->tile*N+3;

            if(col<=8&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))){
                grille[row][col+1]->tile=0;
            }// right one condition
            if(row>=1&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))){
                grille[row-1][col]->tile=0;
            }// up one condition

            if(grille[row][col-2]->tile/N!=0)FiveNum[0]=grille[row][col-2]->tile%N;
            if(grille[row][col-1]->tile/N!=0)FiveNum[1]=grille[row][col-1]->tile%N;
            FiveNum[2]=grille[row][col]->tile;
            if(grille[row+1][col]->tile/N!=0)FiveNum[3]=grille[row+1][col]->tile%N;
            if(grille[row+2][col]->tile/N!=0)FiveNum[4]=grille[row+2][col]->tile%N;

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
            focus->tile=focus->tile*N+3;

            if(col>=1&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))){
                grille[row][col-1]->tile=0;
            }// left one condition
            if(row<=8&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))){
                grille[row+1][col]->tile=0;
            }// down one condition

            if(grille[row][col+1]->tile/N!=0)FiveNum[0]=grille[row][col+1]->tile%N;
            if(grille[row][col+2]->tile/N!=0)FiveNum[1]=grille[row][col+2]->tile%N;
            FiveNum[2]=grille[row][col]->tile;
            if(grille[row-2][col]->tile/N!=0)FiveNum[3]=grille[row-2][col]->tile%N;
            if(grille[row-1][col]->tile/N!=0)FiveNum[4]=grille[row-1][col]->tile%N;

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
            focus->tile=focus->tile*N+3;

            if(col>=1&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))){
                grille[row][col-1]->tile=0;
            }// left one condition
            if(row>=1&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))){
                grille[row-1][col]->tile=0;
            }// up one condition

            if(grille[row][col+1]->tile/N!=0)FiveNum[0]=grille[row][col+1]->tile%N;
            if(grille[row][col+2]->tile/N!=0)FiveNum[1]=grille[row][col+2]->tile%N;
            FiveNum[2]=grille[row][col]->tile;
            if(grille[row+1][col]->tile/N!=0)FiveNum[3]=grille[row+1][col]->tile%N;
            if(grille[row+2][col]->tile/N!=0)FiveNum[4]=grille[row+2][col]->tile%N;

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
            focus->tile=focus->tile*N+3;

            if(grille[row][col-2]->tile/N!=0)FiveNum[0]=grille[row][col-2]->tile%N;
            if(grille[row][col-1]->tile/N!=0)FiveNum[1]=grille[row][col-1]->tile%N;
            if(grille[row-1][col]->tile/N!=0)FiveNum[2]=grille[row-1][col]->tile%N;
            FiveNum[3]=grille[row][col]->tile;
            if(grille[row+1][col]->tile/N!=0)FiveNum[4]=grille[row+1][col]->tile%N;

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
            focus->tile=focus->tile*N+3;

            if(grille[row][col+1]->tile/N!=0)FiveNum[0]=grille[row][col+1]->tile%N;
            if(grille[row][col+2]->tile/N!=0)FiveNum[1]=grille[row][col+2]->tile%N;
            if(grille[row-1][col]->tile/N!=0)FiveNum[2]=grille[row-1][col]->tile%N;
            FiveNum[3]=grille[row][col]->tile;
            if(grille[row+1][col]->tile/N!=0)FiveNum[4]=grille[row+1][col]->tile%N;

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
            focus->tile=focus->tile*N+3;

            if(grille[row][col-1]->tile/N!=0)FiveNum[0]=grille[row][col-1]->tile%N;
            FiveNum[1]=grille[row][col]->tile;
            if(grille[row][col+1]->tile/N!=0)FiveNum[2]=grille[row][col+1]->tile%N;
            if(grille[row-2][col]->tile/N!=0)FiveNum[3]=grille[row-2][col]->tile%N;
            if(grille[row-1][col]->tile/N!=0)FiveNum[4]=grille[row-1][col]->tile%N;

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
            focus->tile=focus->tile*N+3;

            if(grille[row][col-1]->tile/N!=0)FiveNum[0]=grille[row][col-1]->tile%N;
            FiveNum[1]=grille[row][col]->tile;
            if(grille[row][col+1]->tile/N!=0)FiveNum[2]=grille[row][col+1]->tile%N;
            if(grille[row+1][col]->tile/N!=0)FiveNum[3]=grille[row+1][col]->tile%N;
            if(grille[row+2][col]->tile/N!=0)FiveNum[4]=grille[row+2][col]->tile%N;

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
            num/=N;

            if(col<=8&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))){
                grille[row][col+1]->tile=0;
            }// right one condition
            if(row<=8&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))){
                grille[row+1][col]->tile=0;
            }// down one condition

            if(grille[row][col-2]->tile/N!=0)FiveNum[0]=grille[row][col-2]->tile%N;
            if(grille[row][col-1]->tile/N!=0)FiveNum[1]=grille[row][col-1]->tile%N;
            FiveNum[2]=grille[row][col]->tile%N;
            if(grille[row-2][col]->tile/N!=0)FiveNum[3]=grille[row-2][col]->tile%N;
            if(grille[row-1][col]->tile/N!=0)FiveNum[4]=grille[row-1][col]->tile%N;

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
        case N: // left down special component
            num/=N;

            if(col<=8&&((num==grille[row][col+1]->tile)||(num==grille[row][col+1]->tile/N))){
                grille[row][col+1]->tile=0;
            }// right one condition
            if(row>=1&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))){
                grille[row-1][col]->tile=0;
            }// up one condition

            if(grille[row][col-2]->tile/N!=0)FiveNum[0]=grille[row][col-2]->tile%N;
            if(grille[row][col-1]->tile/N!=0)FiveNum[1]=grille[row][col-1]->tile%N;
            FiveNum[2]=grille[row][col]->tile%N;
            if(grille[row+1][col]->tile/N!=0)FiveNum[3]=grille[row+1][col]->tile%N;
            if(grille[row+2][col]->tile/N!=0)FiveNum[4]=grille[row+2][col]->tile%N;

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
            num/=N;

            if(col>=1&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))){
                grille[row][col-1]->tile=0;
            }// left one condition
            if(row<=8&&((num==grille[row+1][col]->tile)||(num==grille[row+1][col]->tile/N))){
                grille[row+1][col]->tile=0;
            }// down one condition

            if(grille[row][col+1]->tile/N!=0)FiveNum[0]=grille[row][col+1]->tile%N;
            if(grille[row][col+2]->tile/N!=0)FiveNum[1]=grille[row][col+2]->tile%N;
            FiveNum[2]=grille[row][col]->tile%N;
            if(grille[row-1][col]->tile/N!=0)FiveNum[3]=grille[row-1][col]->tile%N;
            if(grille[row-2][col]->tile/N!=0)FiveNum[4]=grille[row-2][col]->tile%N;

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
            num/=N;

            if(col>=1&&((num==grille[row][col-1]->tile)||(num==grille[row][col-1]->tile/N))){
                grille[row][col-1]->tile=0;
            }// left one condition
            if(row>=1&&((num==grille[row-1][col]->tile)||(num==grille[row-1][col]->tile/N))){
                grille[row-1][col]->tile=0;
            }// up one condition

            if(grille[row][col+1]->tile/N!=0)FiveNum[0]=grille[row][col+1]->tile%N;
            if(grille[row][col+2]->tile/N!=0)FiveNum[1]=grille[row][col+2]->tile%N;
            FiveNum[2]=grille[row][col]->tile%N;
            if(grille[row+1][col]->tile/N!=0)FiveNum[3]=grille[row+1][col]->tile%N;
            if(grille[row+2][col]->tile/N!=0)FiveNum[4]=grille[row+2][col]->tile%N;

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
            num/=N;

            if(grille[row][col-2]->tile/N!=0)FiveNum[0]=grille[row][col-2]->tile%N;
            if(grille[row][col-1]->tile/N!=0)FiveNum[1]=grille[row][col-1]->tile%N;
            if(grille[row-1][col]->tile/N!=0)FiveNum[2]=grille[row-1][col]->tile%N;
            FiveNum[3]=grille[row][col]->tile%N;
            if(grille[row+1][col]->tile/N!=0)FiveNum[4]=grille[row+1][col]->tile%N;

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
            num/=N;

            if(grille[row][col+1]->tile/N!=0)FiveNum[0]=grille[row][col+1]->tile%N;
            if(grille[row][col+2]->tile/N!=0)FiveNum[1]=grille[row][col+2]->tile%N;
            if(grille[row-1][col]->tile/N!=0)FiveNum[2]=grille[row-1][col]->tile%N;
            FiveNum[3]=grille[row][col]->tile%N;
            if(grille[row+1][col]->tile/N!=0)FiveNum[4]=grille[row+1][col]->tile%N;

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
            num/=N;

            if(grille[row][col-1]->tile/N!=0)FiveNum[0]=grille[row][col-1]->tile%N;
            FiveNum[1]=grille[row][col]->tile%N;
            if(grille[row][col+1]->tile/N!=0)FiveNum[2]=grille[row][col+1]->tile%N;
            if(grille[row-2][col]->tile/N!=0)FiveNum[3]=grille[row-2][col]->tile%N;
            if(grille[row-1][col]->tile/N!=0)FiveNum[4]=grille[row-1][col]->tile%N;

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
            num/=N;

            if(grille[row][col-1]->tile/N!=0)FiveNum[0]=grille[row][col-1]->tile%N;
            FiveNum[1]=grille[row][col]->tile%N;
            if(grille[row][col+1]->tile/N!=0)FiveNum[2]=grille[row][col+1]->tile%N;
            if(grille[row+1][col]->tile/N!=0)FiveNum[3]=grille[row+1][col]->tile%N;
            if(grille[row+2][col]->tile/N!=0)FiveNum[4]=grille[row+2][col]->tile%N;

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



void Selection_block::elimination(Grille *grille[N][N], Grille *focus)
{
    focus->tile=0;
    int row=focus->row;
    int col=focus->col;
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
    int row= focus->row;
       int col= focus->col;
       int num= focus->tile;

       if (num!=0 && num!=5)
       {
           if (num/N==0)
           {
               if (row<=7 && col>=2 && ((num==grille[row][col-2]->tile) || (num==grille[row][col-2]->tile/N)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/N)) && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/N)) && ((num==grille[row+2][col]->tile) || (num==grille[row+2][col]->tile/N)))
               {return 1;}//L1 without bomb

               if (row>=2 && col>=2 && ((num==grille[row-2][col]->tile) || (num==grille[row-2][col]->tile/N)) && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/N)) && ((num==grille[row][col-2]->tile) || (num==grille[row][col-2]->tile/N)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/N)))
               {return 2;}//L2 without bomb

               if (row<=7 && col<=7 && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/N)) && ((num==grille[row+2][col]->tile) || (num==grille[row+2][col]->tile/N)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/N)) && ((num==grille[row][col+2]->tile) || (num==grille[row][col+2]->tile/N)))
               {return 3;}//L3 without bomb

               if (row>=2&& col<=7 && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/N)) && ((num==grille[row-2][col]->tile) || (num==grille[row-2][col]->tile/N)) && ((num==grille[row][col+2]->tile) || (num==grille[row][col+2]->tile/N)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/N)))
               {return 4;}//L4 without bomb

               if (row>=2 && col>=1 && col<=8 && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/N)) && ((num==grille[row-2][col]->tile) || (num==grille[row-2][col]->tile/N)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/N)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/N)))
               {return 9;}//T1 without bomb

               if (row<=7 && col>=1 && col<=8 && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/N)) && ((num==grille[row+2][col]->tile) || (num==grille[row+2][col]->tile/N)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/N)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/N)))
               {return N;}//T2 without bomb

               if (row>=1 && row<=8 && col<=7 && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/N)) && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/N)) && ((num==grille[row][col+2]->tile) || (num==grille[row][col+2]->tile/N)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/N)))
               {return 11;}//T3 without bomb

               if (row>=1 && row<=8 && col>=2 && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/N)) && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/N)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/N)) && ((num==grille[row][col-2]->tile) || (num==grille[row][col-2]->tile/N)))
               {return 12;}//T4 without bomb


           }
           else
           {
               num/=N;//determine the color

               if (row<=7 && col>=2 && ((num==grille[row][col-2]->tile) || (num==grille[row][col-2]->tile/N)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/N)) && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/N)) && ((num==grille[row+2][col]->tile) || (num==grille[row+2][col]->tile/N)))
               {return 5;}//L1 with bomb

               if (row>=2 && col>=2 && ((num==grille[row-2][col]->tile) || (num==grille[row-2][col]->tile/N)) && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/N)) && ((num==grille[row][col-2]->tile) || (num==grille[row][col-2]->tile/N)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/N)))
               {return 6;}//L2 with bomb

               if (row<=7 && col<=7 && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/N)) && ((num==grille[row+2][col]->tile) || (num==grille[row+2][col]->tile/N)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/N)) && ((num==grille[row][col+2]->tile) || (num==grille[row][col+2]->tile/N)))
               {return 7;}//L3 with bomb

               if (row>=2&& col<=7 && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/N)) && ((num==grille[row-2][col]->tile) || (num==grille[row-2][col]->tile/N)) && ((num==grille[row][col+2]->tile) || (num==grille[row][col+2]->tile/N)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/N)))
               {return 8;}//L4 with bomb

               if (row>=2 && col>=1 && col<=8 && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/N)) && ((num==grille[row-2][col]->tile) || (num==grille[row-2][col]->tile/N)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/N)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/N)))
               {return 13;}//T1 without bomb

               if (row<=7 && col>=1 && col<=8 && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/N)) && ((num==grille[row+2][col]->tile) || (num==grille[row+2][col]->tile/N)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/N)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/N)))
               {return 14;}//T2 without bomb

               if (row>=1 && row<=8 && col<=7 && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/N)) && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/N)) && ((num==grille[row][col+2]->tile) || (num==grille[row][col+2]->tile/N)) && ((num==grille[row][col+1]->tile) || (num==grille[row][col+1]->tile/N)))
               {return 15;}//T3 without bomb

               if (row>=1 && row<=8 && col>=2 && ((num==grille[row+1][col]->tile) || (num==grille[row+1][col]->tile/N)) && ((num==grille[row-1][col]->tile) || (num==grille[row-1][col]->tile/N)) && ((num==grille[row][col-1]->tile) || (num==grille[row][col-1]->tile/N)) && ((num==grille[row][col-2]->tile) || (num==grille[row][col-2]->tile/N)))
               {return 16;}//T4 without bomb
           }
       }
       return 0;
}

Selection_block::~Selection_block()
{

}

