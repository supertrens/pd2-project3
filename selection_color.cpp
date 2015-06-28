#include "selection_color.h"
#include "destroy.h"
#include "destroy_vertical.h"
#include "destroy_horizontal.h"
#include "selection_block.h"
#include "grille.h"
#include "central.h"

#include <QDebug>

Selection_Color::Selection_Color()
{

}

void Selection_Color::selection(Grille * grille[N][N],Grille * clicked,int mode)
{
    /**************************************************/
}

void Selection_Color::elimination(Grille *grille[N][N], Grille *clicked)
{
    int couleurDestruction; //destroy_color
    int tile_copy[N][N];  //num_copy
    Destroy * d;

    if(clicked->tile!=0){

        if(clicked->tile/N==0)couleurDestruction=clicked->tile;
        else{couleurDestruction=clicked->tile/N;}

        // copy
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                tile_copy[i][j]=grille[i][j]->tile;
            }
        } // end copy

        // use copy to destroy
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(tile_copy[i][j]==couleurDestruction){
                    grille[i][j]->tile=0;
                }
                else if((tile_copy[i][j]/N!=0)&&(tile_copy[i][j]/N==couleurDestruction)){
                    switch (tile_copy[i][j]%N) {
                    case 1: // vertical bomb
                        d=new DestroyVertical;
                        d->elimination(grille,grille[i][j]);
                        delete d;
                        break;
                    case 2: // horizontal bomb
                        d=new DestroyHorizontal;
                        d->elimination(grille,grille[i][j]);
                        delete d;
                        break;
                    case 3: // bomb
                        d=new Selection_block;
                        d->elimination(grille,grille[i][j]);
                        delete d;
                        break;
                    default:
                        qDebug()<<"elimination one color error";
                    }
                }
            }
        } // end use copy
    }
}

int Selection_Color::condition(Grille *grille[N][N], Grille *focus)
{
    // garbage function
}

Selection_Color::~Selection_Color()
{

}

