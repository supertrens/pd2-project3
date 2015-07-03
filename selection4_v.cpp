
#include "Selection4_V.h"
#include <QDebug>
#include "destroy.h"
#include "destroy_vertical.h"
#include "destroy_horizontal.h"
#include "Selection_block.h"

Selection4_V::Selection4_V()
{

}

void Selection4_V::selection(Grille *grille[N][N],Grille * focus,int mode)
{
       int row= focus->row;
       int col= focus->col;
       int num= focus->tile;
       int FourNum[4]={0};

       switch(mode){
       case 1://I1 without bomb
           focus->tile =focus->tile*N+1;

           //check for bomb with in the 5 blocks
           if (grille[row-1][col]->tile/N != 0)
               FourNum[0]= grille[row-1][col]->tile%N;
           FourNum[1]=grille[row][col]->tile;
           if (grille[row+1][col]->tile/N != 0)
               FourNum[2]= grille[row+1][col]->tile%N;
           if (grille[row+2][col]->tile/N != 0)
               FourNum[3]= grille[row+2][col]->tile%N;

           //check for the bomb and then Destroy them
           for (int i=0; i<4; i++)
           {
               Destroy *e;

               switch(FourNum[i]){
               case 0://歸零
                   grille[row-1+i][col]->tile=0;break;
               case 1://爆
                   e= new DestroyVertical;
                   e->elimination(grille, grille[row-1+i][col]);
                   delete e;break;
               case 2://爆
                   e= new DestroyHorizontal;
                   e->elimination(grille,grille[row-1+i][col]);
                   delete e;break;
               case 3://爆
                   e= new Selection_block;
                   e->elimination(grille,grille[row-1+i][col]);
                   delete e;break;
               }
           }break;

       case 2://I2 without bomb
           focus->tile=focus->tile*N+1;

           //check for bomb with in the 5 blocks
           if (grille[row-2][col]->tile/N != 0)
               FourNum[0]= grille[row-2][col]->tile%N;
           if (grille[row-1][col]->tile/N != 0)
               FourNum[1]= grille[row-1][col]->tile%N;
           FourNum[2]=grille[row][col]->tile;
           if (grille[row+1][col]->tile/N != 0)
               FourNum[3]= grille[row+1][col]->tile%N;

           //check for the bomb and then Destroy them
           for (int i=0; i<4; i++)
           {
               Destroy *e;

               switch(FourNum[i]){
               case 0://歸零
                   grille[row-2+i][col]->tile=0;break;
               case 1://爆
                   e= new DestroyVertical;
                   e->elimination(grille, grille[row-2+i][col]);
                   delete e;break;
               case 2://爆
                   e= new DestroyHorizontal;
                   e->elimination(grille,grille[row-2+i][col]);
                   delete e;break;
               case 3://爆
                   e= new Selection_block;
                   e->elimination(grille,grille[row-2+i][col]);
                   delete e;break;
               }
           }break;

       case 3://I3 without bomb
           focus->tile=focus->tile*N+2;

           //check for bomb with in the 5 blocks
           if (grille[row][col-1]->tile/N != 0)
               FourNum[0]= grille[row][col-1]->tile%N;
           FourNum[1]=grille[row][col]->tile;
           if (grille[row][col+1]->tile/N != 0)
               FourNum[2]= grille[row][col+1]->tile%N;
           if (grille[row][col+2]->tile/N != 0)
               FourNum[3]= grille[row][col+2]->tile%N;

           //check for the bomb and then Destroy them
           for (int i=0; i<4; i++)
           {
               Destroy *e;

               switch(FourNum[i]){
               case 0://歸零
                   grille[row][col-1+i]->tile=0;break;
               case 1://爆
                   e= new DestroyVertical;
                   e->elimination(grille, grille[row][col-1+i]);
                   delete e;break;
               case 2://爆
                   e= new DestroyHorizontal;
                   e->elimination(grille,grille[row][col-1+i]);
                   delete e;break;
               case 3://爆
                   e= new Selection_block;
                   e->elimination(grille,grille[row][col-1+i]);
                   delete e;break;
               }
           }break;

       case 4://I4 without bomb
           focus->tile=focus->tile*N+2;

           //check for bomb with in the 5 blocks
           if (grille[row][col-2]->tile/N != 0)
               FourNum[0]= grille[row][col-2]->tile%N;
           if (grille[row][col-1]->tile/N != 0)
               FourNum[1]= grille[row][col-1]->tile%N;
           FourNum[2]=grille[row][col]->tile;
           if (grille[row][col+1]->tile/N != 0)
               FourNum[3]= grille[row][col+1]->tile%N;

           //check for the bomb and then Destroy them
           for (int i=0; i<4; i++)
           {
               Destroy *e;

               switch(FourNum[i]){
               case 0://歸零
                   grille[row][col-2+i]->tile=0;break;
               case 1://爆
                   e= new DestroyVertical;
                   e->elimination(grille, grille[row][col-2+i]);
                   delete e;break;
               case 2://爆
                   e= new DestroyHorizontal;
                   e->elimination(grille,grille[row][col-2+i]);
                   delete e;break;
               case 3://爆
                   e= new Selection_block;
                   e->elimination(grille,grille[row][col-2+i]);
                   delete e;break;
               }
           }break;

       case 5://I1 with bomb
           num=num/N;

           //check for bomb with in the 5 blocks
           if (grille[row-1][col]->tile/N != 0)
               FourNum[0]= grille[row-1][col]->tile%N;
           FourNum[1]=grille[row][col]->tile%N;
           if (grille[row+1][col]->tile/N != 0)
               FourNum[2]= grille[row+1][col]->tile%N;
           if (grille[row+2][col]->tile/N != 0)
               FourNum[3]= grille[row+2][col]->tile%N;

           //check for the bomb and then Destroy them
           for (int i=0; i<4; i++)
           {
               Destroy *e;

               switch(FourNum[i]){
               case 0://歸零
                   grille[row-1+i][col]->tile=0;break;
               case 1://爆
                   e= new DestroyVertical;
                   e->elimination(grille, grille[row-1+i][col]);
                   delete e;break;
               case 2://爆
                   e= new DestroyHorizontal;
                   e->elimination(grille,grille[row-1+i][col]);
                   delete e;break;
               case 3://爆
                   e= new Selection_block;
                   e->elimination(grille,grille[row-1+i][col]);
                   delete e;break;
               }
           }break;

       case 6://I2 with bomb
           num=num/N;

           //check for bomb with in the 5 blocks
           if (grille[row-2][col]->tile/N != 0)
               FourNum[0]= grille[row-2][col]->tile%N;
           if (grille[row-1][col]->tile/N != 0)
               FourNum[1]= grille[row-1][col]->tile%N;
           FourNum[2]=grille[row][col]->tile%N;
           if (grille[row+1][col]->tile/N != 0)
               FourNum[3]= grille[row+1][col]->tile%N;

           //check for the bomb and then Destroy them
           for (int i=0; i<4; i++)
           {
               Destroy *e;

               switch(FourNum[i]){
               case 0://歸零
                   grille[row-2+i][col]->tile=0;break;
               case 1://爆
                   e= new DestroyVertical;
                   e->elimination(grille, grille[row-2+i][col]);
                   delete e;break;
               case 2://爆
                   e= new DestroyHorizontal;
                   e->elimination(grille,grille[row-2+i][col]);
                   delete e;break;
               case 3://爆
                   e= new Selection_block;
                   e->elimination(grille,grille[row-2+i][col]);
                   delete e;break;
               }
           }break;

       case 7://I3 with bomb
           num=num/N;

           //check for bomb with in the 5 blocks
           if (grille[row][col-1]->tile/N != 0)
               FourNum[0]= grille[row][col-1]->tile%N;
           FourNum[1]=grille[row][col]->tile%N;
           if (grille[row][col+1]->tile/N != 0)
               FourNum[2]= grille[row][col+1]->tile%N;
           if (grille[row][col+2]->tile/N != 0)
               FourNum[3]= grille[row][col+2]->tile%N;

           //check for the bomb and then Destroy them
           for (int i=0; i<4; i++)
           {
               Destroy *e;

               switch(FourNum[i]){
               case 0://歸零
                   grille[row][col-1+i]->tile=0;break;
               case 1://爆
                   e= new DestroyVertical;
                   e->elimination(grille, grille[row][col-1+i]);
                   delete e;break;
               case 2://爆
                   e= new DestroyHorizontal;
                   e->elimination(grille,grille[row][col-1+i]);
                   delete e;break;
               case 3://爆
                   e= new Selection_block;
                   e->elimination(grille,grille[row][col-1+i]);
                   delete e;break;
               }
           }break;

       case 8://I4 with bomb
           num=num/N;

           //check for bomb with in the 5 blocks
           if (grille[row][col-2]->tile/N != 0)
               FourNum[0]= grille[row][col-2]->tile%N;
           if (grille[row][col-1]->tile/N != 0)
               FourNum[1]= grille[row][col-1]->tile%N;
           FourNum[2]=grille[row][col]->tile%N;
           if (grille[row][col+1]->tile/N != 0)
               FourNum[3]= grille[row][col+1]->tile%N;

           //check for the bomb and then Destroy them
           for (int i=0; i<4; i++)
           {
               Destroy *e;

               switch(FourNum[i]){
               case 0://歸零
                   grille[row][col-2+i]->tile=0;break;
               case 1://爆
                   e= new DestroyVertical;
                   e->elimination(grille, grille[row][col-2+i]);
                   delete e;break;
               case 2://爆
                   e= new DestroyHorizontal;
                   e->elimination(grille,grille[row][col-2+i]);
                   delete e;break;
               case 3://爆
                   e= new Selection_block;
                   e->elimination(grille,grille[row][col-2+i]);
                   delete e;break;
               }
           }break;
       }
}

void Selection4_V::elimination(Grille *grille[N][N],Grille * focus)
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

