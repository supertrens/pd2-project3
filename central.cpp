#include "central.h"
#include <QDebug>
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

Central::Central()
{

}

void Central::selection(Grille *grille[N][N],Grille * clicked,int mode)
{
   /************************************************/
}

void Central::elimination(Grille *grille[N][N],Grille * clicked)
{
    // clicked is garbage value
    //for(int i=0; i<N ; i++){qDebug()<<"in";
     //   for(int j=0;j<N;j++){
       //    grille[i][j]->tile=0;
     //   }
  //  }
}

int Central::condition(Grille *grille[N][N], Grille *focus)
{
    /*****************************************/
}

Central::~Central()
{

}


