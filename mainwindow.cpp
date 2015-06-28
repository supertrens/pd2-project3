#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "destroy_horizontal.h"
#include "destroy_vertical.h"
#include "central.h"
#include "selection3_h.h"
#include "selection3_v.h"
#include "selection4_h.h"
#include "selection4_v.h"
#include "selection5_h.h"
#include "selection5_v.h"
#include "selection_block.h"
#include "selection_color.h"

#include <QPushButton>
#include <QDebug>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Insert the Background Picnture
    QPixmap bkgnd(":/pic/background.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

        for(int i=0 ; i<N ; i++){
               for(int j=0 ; j<N ; j++){
                   grille[i][j]=new Grille(this,i,j);
                   connect(grille[i][j],SIGNAL(Click(int,int)),this,SLOT( candySelected(int,int)));
                   connect(grille[i][j],SIGNAL(moveDone()),this,SLOT(foo()));
               }
           }
           srand(time(NULL));
           isSelected = false;
           startGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
    isSelected = false;
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0; j < N ; j++)
        {
            grille[i][j]->setNumber();
            grille[i][j]->setCandy();
            if(j>=2&&((grille[i][j]->tile)==(grille[i][j-1]->tile))&&((grille[i][j]->tile)==(grille[i][j-2]->tile)))
                 j--; //check the row

            if(i>=2&&((grille[i][j]->tile)==(grille[i-1][j]->tile))&&((grille[i][j]->tile)==(grille[i-2][j]->tile)))
                 j --; // check column
        }
    }
}

void MainWindow::candySelected(int row,int col)
{
    qDebug()<<(grille[row][col]->tile);
    if(isSelected == false)
    {
       setCandySelected(grille[row][col]);
       rowBackUp  = row;
       colBackUp  = col;
       isSelected = true;
    }
    else{
       if(rowBackUp == row && colBackUp == col+1){
           *grille[row][col]- grille[row][col+1]; // change
           if(!Check(row,col,rowBackUp,colBackUp)){
               *grille[row][col]- grille[row][col+1]; // nothing done
           }
       }
       else if(rowBackUp==row&&colBackUp==col-1){
           *grille[row][col-1]-grille[row][col]; // change
           if(!Check(row,col,rowBackUp,colBackUp)){
               *grille[row][col-1]- grille[row][col]; // nothing done
           }
       }
       else if(rowBackUp==row+1&&colBackUp==col){
           *grille[row][col]| grille[row+1][col]; // change
           if(!Check(row,col,rowBackUp,colBackUp)){
               *grille[row][col]| grille[row+1][col]; // nothing done
           }
       }
       else if(rowBackUp==row-1&&colBackUp==col){
           *grille[row-1][col] | grille[row][col]; // change
           if(!Check(row,col,rowBackUp,colBackUp)){
               *grille[row-1][col]| grille[row][col]; // nothing done
           }
       }
       else{
           setCandySelected( grille[rowBackUp][colBackUp] );
       }
       isSelected=false;
    }
    return;
}


bool MainWindow::Check(int row1,int col1,int row2,int col2)
{
    bool noChange[12]={0};

    // check destroy central
    if((grille[row1][col1]->tile==5)&&(grille[row2][col2]->tile==5))
    {
        destroy = new Central;
        destroy->elimination(grille,grille[row1][col1]);
        delete destroy;
        return true;
    }


    // check destroy one color
    if((grille[row1][col1]->tile==5)||(grille[row2][col2]->tile==5))
    {
        if(grille[row1][col1]->tile==5){
            destroy = new Selection_Color;
            destroy->elimination(grille,grille[row2][col2]);
            delete destroy;
            return true;
        }
        if(grille[row2][col2]->tile==5){
            destroy=new Selection_Color;
            destroy->elimination(grille,grille[row1][col1]);
            delete destroy;
            return true;
        }
    }// end check destroy one color

    // check spawn power bomb
    noChange[0]=Check5_V(row1,col1);
    noChange[1]=Check5_V(row2,col2);
    // end check spawn power bomb

    // check spawn bomb
    noChange[2]= Check5_H(row1,col1);
    noChange[3]= Check5_H(row2,col2);
    // end check spawn bomb

    // check spawn vertical bomb
    noChange[4]=Check4_V(row1,col1);
    noChange[5]=Check4_V(row2,col2);
    // end check spawn vertical bomb

    // check spawn horizontal bomb
    noChange[6]=Check4_H(row1,col1);
    noChange[7]=Check4_H(row2,col2);
    // end check spawn horizontal bomb

    // check destroy vertical 3
    noChange[8]=Check3_V(row1,col1);
    noChange[9]=Check3_V(row2,col2);
    // end check destroy horizontal 3

    // check destroy vertical 3
    noChange[10]=Check3_H(row1,col1);
    noChange[11]=Check3_H(row2,col2);
    // end check destroy horizontal 3

    for(int i=0;i<12;i++){
        if(noChange[i]==true)
            return true;
    }
    return false;
}

bool MainWindow::Check3_H(int row, int col)
{
    int return_value;
    bool AnySpawn = false;
    destroy = new Selection3_H; //H
    return_value=destroy->condition(grille,grille[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // leftest normal component
            destroy->selection(grille,grille[row][col],1);
            AnySpawn=true;
            break;
        case 2: // middle normal component
            destroy->selection(grille,grille[row][col],2);
            AnySpawn=true;
            break;
        case 3: // rightest special component
            destroy->selection(grille,grille[row][col],3);
            AnySpawn=true;
            break;
        case 4: // leftest special component
            destroy->selection(grille,grille[row][col],4);
            AnySpawn=true;
            break;
        case 5: // middle special component
            destroy->selection(grille,grille[row][col],5);
            AnySpawn=true;
            break;
        case 6: // rightest special component
            destroy->selection(grille,grille[row][col],6);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"Check3_H error";
        }
    }
    delete destroy;
    return AnySpawn;

}

bool MainWindow::Check3_V(int row, int col)
{

    int return_value;
    bool AnySpawn=false;
    destroy=new Selection3_V;
    return_value=destroy->condition(grille,grille[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // leftest normal component
            destroy->selection(grille,grille[row][col],1);
            AnySpawn=true;
            break;
        case 2: // middle normal component
            destroy->selection(grille,grille[row][col],2);
            AnySpawn=true;
            break;
        case 3: // rightest special component
            destroy->selection(grille,grille[row][col],3);
            AnySpawn=true;
            break;
        case 4: // leftest special component
            destroy->selection(grille,grille[row][col],4);
            AnySpawn=true;
            break;
        case 5: // middle special component
            destroy->selection(grille,grille[row][col],5);
            AnySpawn=true;
            break;
        case 6: // rightest special component
            destroy->selection(grille,grille[row][col],6);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"Check3_V error";
        }
    }
    delete destroy;
    return AnySpawn;
}

void MainWindow::setCandySelected(Grille* grille)
{
    // 1 red, 2 yellow, 3 green, 4 blue
    if(!isSelected){
        switch(grille->tile){
            case 1:
                grille->button->setIcon(QIcon(QPixmap(":/pic/red_clicked.png")));
                break;
            case 11:
                grille->button->setIcon(QIcon(QPixmap(":/pic/red_vertical_bomb_clicked.png")));
                break;
            case 12:
                grille->button->setIcon(QIcon(QPixmap(":/pic/red_horizontal_bomb_clicked.png")));
                break;
            case 13:
                grille->button->setIcon(QIcon(QPixmap(":/pic/red_bomb_clicked.png")));
                break;
            case 2:
                grille->button->setIcon(QIcon(QPixmap(":/pic/yellow_clicked.png")));
                break;
            case 21:
                grille->button->setIcon(QIcon(QPixmap(":/pic/yellow_vertical_bomb_clicked.png")));
                break;
            case 22:
                grille->button->setIcon(QIcon(QPixmap(":/pic/yellow_horizontal_bomb_clicked.png")));
                break;
            case 23:
                grille->button->setIcon(QIcon(QPixmap(":/pic/yellow_bomb_clicked.png")));
                break;
            case 3:
                grille->button->setIcon(QIcon(QPixmap(":/pic/green_clicked.png")));
                break;
            case 31:
                grille->button->setIcon(QIcon(QPixmap(":/pic/green_vertical_bomb_clicked.png")));
                break;
            case 32:
                grille->button->setIcon(QIcon(QPixmap(":/pic/green_horizontal_bomb_clicked.png")));
                break;
            case 33:
                grille->button->setIcon(QIcon(QPixmap(":/pic/green_bomb_clicked.png")));
                break;
            case 4:
                grille->button->setIcon(QIcon(QPixmap(":/pic/blue_clicked.png")));
                break;
            case 41:
                grille->button->setIcon(QIcon(QPixmap(":/pic/blue_vertical_bomb_clicked.png")));
                break;
            case 42:
                grille->button->setIcon(QIcon(QPixmap(":/pic/blue_horizontal_bomb_clicked.png")));
                break;
            case 43:
                grille->button->setIcon(QIcon(QPixmap(":/pic/blue_bomb_clicked.png")));
                break;
            case 5:
                grille->button->setIcon(QIcon(QPixmap(":/pic/power_bomb_clicked.png")));
                break;
        }
    }
    else{
        grille->setCandy();
    }
    return;
}

bool MainWindow::Check5_H(int row, int col)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Selection5_H;
    return_value=destroy->condition(grille,grille[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // vertical normal component
            destroy->selection(grille,grille[row][col],1);
            AnySpawn=true;
            break;
        case 2: // horizontal normal component
            destroy->selection(grille,grille[row][col],2);
            AnySpawn=true;
            break;
        case 3: // vertical special component
            destroy->selection(grille,grille[row][col],3);
            AnySpawn=true;
            break;
        case 4: // horizontal special component
            destroy->selection(grille,grille[row][col],4);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"Check5_H error";
        }
    }
    delete destroy;
    return AnySpawn;
}

bool MainWindow::Check5_V (int row, int col)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Selection5_V;
    return_value=destroy->condition(grille,grille[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // left up normal component
            destroy->selection(grille,grille[row][col],1);
            AnySpawn=true;
            break;
        case 2: // left down normal component
            destroy->selection(grille,grille[row][col],2);
            AnySpawn=true;
            break;
        case 3: // right up normal component
            destroy->selection(grille,grille[row][col],3);
            AnySpawn=true;
            break;
        case 4: // right down normal component
            destroy->selection(grille,grille[row][col],4);
            AnySpawn=true;
            break;
        case 5: // left T normal component
            destroy->selection(grille,grille[row][col],5);
            AnySpawn=true;
            break;
        case 6: // right T normal component
            destroy->selection(grille,grille[row][col],6);
            AnySpawn=true;
            break;
        case 7: // up T normal component
            destroy->selection(grille,grille[row][col],7);
            AnySpawn=true;
            break;
        case 8: // down T normal component
            destroy->selection(grille,grille[row][col],8);
            AnySpawn=true;
            break;
        case 9: // left up special component
            destroy->selection(grille,grille[row][col],9);
            AnySpawn=true;
            break;
        case 10: // left down special component
            destroy->selection(grille,grille[row][col],10);
            AnySpawn=true;
            break;
        case 11: // right up special component
            destroy->selection(grille,grille[row][col],11);
            AnySpawn=true;
            break;
        case 12: // right down special component
            destroy->selection(grille,grille[row][col],12);
            AnySpawn=true;
            break;
        case 13: // left T special component
            destroy->selection(grille,grille[row][col],13);
            AnySpawn=true;
            break;
        case 14: // right T special component
            destroy->selection(grille,grille[row][col],14);
            AnySpawn=true;
            break;
        case 15: // up T special component
            destroy->selection(grille,grille[row][col],15);
            AnySpawn=true;
            break;
        case 16: // down T special component
            destroy->selection(grille,grille[row][col],16);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"Check5_v error";
        }
    }
    delete destroy;
    return AnySpawn;
}

bool MainWindow::Check4_V(int row, int col)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Selection4_V;

    return_value=destroy->condition(grille,grille[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // O normal component
                // X
                // O
                // O
            destroy->selection(grille,grille[row][col],1);
            AnySpawn=true;
            break;
        case 2: // O normal component
                // O
                // X
                // O
            destroy->selection(grille,grille[row][col],2);
            AnySpawn=true;
            break;
        case 3: // O special component
                // X
                // O
                // O
            destroy->selection(grille,grille[row][col],3);
            AnySpawn=true;
            break;
        case 4: // O special component
                // O
                // X
                // O
            destroy->selection(grille,grille[row][col],4);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"Check4_v error";
        }
    }
    delete destroy;
    return AnySpawn;
}


bool MainWindow::Check4_H(int row, int col)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Selection4_H;
    return_value=destroy->condition(grille,grille[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // OXOO normal component
            destroy->selection(grille,grille[row][col],1);
            AnySpawn=true;
            break;
        case 2: // OOXO normal component
            destroy->selection(grille,grille[row][col],2);
            AnySpawn=true;
            break;
        case 3: // OOXO special component
            destroy->selection(grille,grille[row][col],3);
            AnySpawn=true;
            break;
        case 4: // OOXO special component
            destroy->selection(grille,grille[row][col],4);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"Check4_H error";
        }
    }
    delete destroy;
    return AnySpawn;
}

void MainWindow::refreshCandy()
{
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            grille[i][j]->setCandy();
}

bool MainWindow::effacerLesPossibilites()
{
    bool possibilite=false; //#still can eliminate

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(possibilite= Check5_H(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(possibilite= Check5_V(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(possibilite= Check4_V(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(possibilite = Check4_H(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(possibilite = Check3_V(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(possibilite= Check3_H(i,j))return true;
        }
    }

    return possibilite;
}

void MainWindow::remplirVide() //Move Fillzero
{
    // move all blocks to fill in zeros
    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            for(int k=i-1;k>=0;k--){
                if(i!=0&&grille[i][j]->tile==0&&grille[k][j]->tile!=0){
                    grille[i][j]->tile= grille[k][j]->tile;
                    grille[k][j]->tile=0;
                }
            }
        }
    } // end move
}

void MainWindow::selectionApresElimination()
{
    // spawn new number for zeros
    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            if(grille[i][j]->tile==0){
                grille[i][j]->setNumber();
                if(j>=2&&(grille[i][j]->tile==grille[i][j-2]->tile)&&(grille[i][j]->tile==grille[i][j-1]->tile)){
                    grille[i][j]->tile=0;
                    j++;
                }//left condition
                else if(j<=7&&(grille[i][j]->tile==grille[i][j+1]->tile)&&(grille[i][j]->tile==grille[i][j+2]->tile)){
                    grille[i][j]->tile=0;
                    j++;
                }//right condition
                else if(i<=7&&(grille[i][j]->tile==grille[i+1][j]->tile)&&(grille[i][j]->tile==grille[i+2][j]->tile)){
                    grille[i][j]->tile=0;
                    j++;
                }//down condition
                else if(j>=1&&j<=8&&(grille[i][j]->tile==grille[i][j-1]->tile)&&(grille[i][j]->tile==grille[i][j+1]->tile)){
                    grille[i][j]->tile=0;
                    j++;
                }//middle condition
            }
        }
    }// end spawn
    refreshCandy();
}

void MainWindow::foo()
{
    refreshCandy();
}
