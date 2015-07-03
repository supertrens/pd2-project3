#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

#include "destroy.h"
#include "destroy_horizontal.h"
#include "destroy_vertical.h"
#include "central.h"
#include "selection3_h.h"
#include "selection3_v.h"
#include "selection4_h.h"
#include "selection4_v.h"
#include "selection5_h.h"
#include "selection5_v.h"
#include "Selection_block.h"
#include "selection_color.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Insert the Background Picnture
       QPixmap bkgnd(":/pic/picture/background.png");
           bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Background, bkgnd);
           this->setPalette(palette);

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            grille[i][j]= new Grille(this, i, j);
            connect(grille[i][j], SIGNAL(Click(int,int)), this, SLOT(button_clicked(int, int)));
            connect(grille[i][j], SIGNAL(moveDone()), this, SLOT(foo()));
        }
    }

    gameStart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gameStart()
{

    score=0;
    score_str = QString::number(score,10);
    ui->scoreText->setText(score_str);

    step = 25;
    step_str= QString::number(step,10);
    ui->stepText->setText(step_str);

    for(int i=0; i<10; i++)//row
    {
        for (int j=0; j<10; j++)//column
        {
            grille[i][j]->setNumber();
            grille[i][j]->setCandy();

            if (j>=2 && (grille[i][j]->tile == grille[i][j-2]->tile) && (grille[i][j]->tile == grille[i][j-1]->tile))
            {
                j--;
            }

            if (i>=2 && (grille[i][j]->tile == grille[i-2][j]->tile) && (grille[i][j]->tile == grille[i-1][j]->tile))
            {
                j--;
            }
        }
    }
}

void MainWindow::setClickPicture(Grille *grille)
{
    if(!isClicked)
    {
        switch(grille->tile){
                    case 1:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/picture/Cupcake-Highlighted.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 11:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/red_vertical_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 12:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/red_horizontal_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 13:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/red_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 2:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/picture/Croissant-Highlighted.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 21:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/yellow_vertical_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 22:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/yellow_horizontal_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 23:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/yellow_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 3:
                        grille->button->setIcon(QIcon(QPixmap(":/pic//picture/Macaroon-Highlighted.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 31:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/green_vertical_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 32:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/green_horizontal_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 33:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/green_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 4:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/picture/Donut-Highlighted.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 41:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/blue_vertical_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 42:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/blue_horizontal_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 43:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/blue_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;
                    case 5:
                        grille->button->setIcon(QIcon(QPixmap(":/pic/power_bomb_clicked.png")));
                         grille->button->setIconSize(grille->button->size());
                        break;

            }
    }
    else

        grille->setCandy();
}


bool MainWindow::check(int row1, int col1, int row2, int col2)
{

    bool dechouke_el[13] ={0} ;
    dechouke_el[0]= checkDoubleStar(row1, col1, row2, col2);
    dechouke_el[1]= checkBombStar(row1, col1, row2, col2);
    dechouke_el[2]= checkOneStar(row1, col1, row2, col2);
    dechouke_el[3]= checkStar(row1, col1);
    dechouke_el[4]= checkStar(row2, col2);
    dechouke_el[5]= checkBox(row1, col1);
    dechouke_el[6]= checkBox(row2, col2);
    dechouke_el[7] = checkLine(row1, col1);
    dechouke_el[8] = checkLine(row2, col2);
    dechouke_el[9] = checkHorThree(row1, col1);
    dechouke_el[10]= checkHorThree(row2, col2);
    dechouke_el[11]= checkVerThree(row1, col1);
    dechouke_el[12]= checkVerThree(row2, col2);

    if (dechouke_el[0]) {score=score+2000;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[1]) {score=score+1500;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[2]) {score=score+1000;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[3]) {score=score+800;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[4]) {score=score+800;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[5]) {score=score+500;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[6]) {score=score+500;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[7]) {score=score+250;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[8]) {score=score+250;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[9]) {score=score+100;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[10]) {score=score+100;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[11]) {score=score+100;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}
    if (dechouke_el[12]) {score=score+100;score_str= QString::number(score,10);ui->scoreText->setText(score_str);}


    for (int i=0; i<13; i++)
     if (dechouke_el[i]==true)
        {
            step = step - 1;
            step_str = QString::number(step,10);
            ui->stepText->setText(step_str);
            return true;
        }

    return false;
}



bool MainWindow::checkDoubleStar(int row1, int col1, int row2, int col2)
{
    bool qqch=false;
    if (grille[row1][col1]->tile==5 && grille[row2][col2]->tile==5)
    {

        for (int i=0; i<10; i++)
            for (int j=0; j<10; j++)
                grille[i][j]->tile=0;

        resetMap();
        qqch=true;
    }
    return qqch;
}


bool MainWindow::checkBombStar(int row1, int col1, int row2, int col2)
{
    bool qqch=false;
    if (grille[row1][col1]->tile==5 && grille[row2][col2]->tile>10 && grille[row2][col2]->tile%10!=0)
    {

        int color= grille[row2][col2]->tile/10;
        int bomb= grille[row2][col2]->tile%10;

        grille[row1][col1]->tile=grille[row2][col2]->tile;
        grille[row2][col2]->tile=0;
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                if (grille[i][j]->tile==color)
                {
                    grille[i][j]->tile=color*10+bomb;
                    switch(bomb)
                    {
                  //  Destroy *e;
                    case 1:
                        e= new DestroyVertical;
                        e->elimination(grille, grille[i][j]);
                        delete e;break;
                    case 2:
                        e= new DestroyHorizontal;
                        e->elimination(grille,grille[i][j]);
                        delete e;break;
                    case 3://爆
                        e= new Selection_block;
                        e->elimination(grille,grille[i][j]);
                        delete e;break;
                    }
                }
            }
        }qqch=true;
    }

    if (grille[row2][col2]->tile==5 && grille[row1][col1]->tile>10 && grille[row1][col1]->tile%10!=0)
    {
        qDebug() << "Bomb Star-2";
        int color= grille[row1][col1]->tile/10;
        int bomb= grille[row1][col1]->tile%10;
        grille[row2][col2]->tile=grille[row1][col1]->tile;
        grille[row1][col1]->tile=0;
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                if (grille[i][j]->tile==color)
                {
                    grille[i][j]->tile=color*10+bomb;
                    switch(bomb){
                    //Destroy *e;
                    case 1://爆
                        e= new DestroyVertical;
                        e->elimination(grille, grille[i][j]);
                        delete e;break;
                    case 2://爆
                        e= new DestroyHorizontal;
                        e->elimination(grille,grille[i][j]);
                        delete e;break;
                    case 3://爆
                        e= new Selection_block;
                        e->elimination(grille,grille[i][j]);
                        delete e;break;
                    }
                }
            }
        }qqch=true;
    }return qqch;
}

bool MainWindow::checkOneStar(int row1, int col1, int row2, int col2)
{
    bool qqch=false;
    if (grille[row1][col1]->tile==5 && grille[row2][col2]->tile<5 )
    {
        qDebug() << "One Star-1";
        int color= grille[row2][col2]->tile;
        grille[row1][col1]->tile=grille[row2][col2]->tile;
        grille[row2][col2]->tile=0;
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                if (grille[i][j]->tile/10==color || grille[i][j]->tile==color)
                    grille[i][j]->tile=0;
            }
        }qqch=true;
    }
    if (grille[row2][col2]->tile==5 && grille[row1][col1]->tile<=5 )
    {
        qDebug() << "One Star-2";
        int color= grille[row1][col1]->tile;
        grille[row2][col2]->tile=grille[row1][col1]->tile;
        grille[row1][col1]->tile=0;
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                if (grille[i][j]->tile/10==color || grille[i][j]->tile==color)
                    grille[i][j]->tile=0;
            }
        }qqch=true;
    }
    return qqch;
}

bool MainWindow::checkStar(int row, int col)
{
    int returnValue;
    bool qqch=false;

    Destroy *e= new Selection5_V;
    returnValue= e->condition(grille, grille[row][col]);

    if (returnValue)
    {
        switch(returnValue){
        case 1:
            e->selection(grille,grille[row][col],1);
            qqch=true;break;
        case 2:
            e->selection(grille,grille[row][col],2);
            qqch=true;break;
        case 3:
            e->selection(grille,grille[row][col],3);
            qqch=true;break;
        case 4:
            e->selection(grille,grille[row][col],4);
            qqch=true;break;

        }
    }
    delete e;
    return qqch;
}

bool MainWindow::checkBox(int row, int col)
{
    int returnValue;
    bool qqch=false;

    Destroy *e= new Selection_block;
    returnValue= e->condition(grille, grille[row][col]);

    if (returnValue)
    {
        switch(returnValue){
        case 1:
            e->selection(grille,grille[row][col],1);
            qqch=true;break;
        case 2:
            e->selection(grille,grille[row][col],2);
            qqch=true;break;
        case 3:
            e->selection(grille,grille[row][col],3);
            qqch=true;break;
        case 4:
            e->selection(grille,grille[row][col],4);
            qqch=true;break;
        case 5:
            e->selection(grille,grille[row][col],5);
            qqch=true;break;
        case 6:
            e->selection(grille,grille[row][col],6);
            qqch=true;break;
        case 7:
            e->selection(grille,grille[row][col],7);
            qqch=true;break;
        case 8:
            e->selection(grille,grille[row][col],8);
            qqch=true;break;
        case 9:
            e->selection(grille,grille[row][col],9);
            qqch=true;break;
        case 10:
            e->selection(grille,grille[row][col],10);
            qqch=true;break;
        case 11:
            e->selection(grille,grille[row][col],11);
            qqch=true;break;
        case 12:
            e->selection(grille,grille[row][col],12);
            qqch=true;break;
        case 13:
            e->selection(grille,grille[row][col],13);
            qqch=true;break;
        case 14:
            e->selection(grille,grille[row][col],14);
            qqch=true;break;
        case 15:
            e->selection(grille,grille[row][col],15);
            qqch=true;break;
        case 16:
            e->selection(grille,grille[row][col],16);
            qqch=true;break;
        }
    }
    delete e;
    return qqch;
}

bool MainWindow::checkLine(int row, int col)
{
    int returnValue;
    bool qqch=false;

    Destroy *e= new Selection4_V;
    returnValue= e->condition(grille, grille[row][col]);

    if (returnValue)
    {
        switch(returnValue){
        case 1:
            e->selection(grille,grille[row][col],1);
            qqch=true;break;
        case 2:
            e->selection(grille,grille[row][col],2);
            qqch=true;break;
        case 3:
            e->selection(grille,grille[row][col],3);
            qqch=true;break;
        case 4:
            e->selection(grille,grille[row][col],4);
            qqch=true;break;
        case 5:
            e->selection(grille,grille[row][col],5);
            qqch=true;break;
        case 6:
            e->selection(grille,grille[row][col],6);
            qqch=true;break;
        case 7:
            e->selection(grille,grille[row][col],7);
            qqch=true;break;
        case 8:
            e->selection(grille,grille[row][col],8);
            qqch=true;break;
        }
    }
    delete e;
    return qqch;
}

bool MainWindow::checkHorThree(int row, int col)
{
    int returnValue;
    bool qqch=false;

    Destroy *e= new Selection3_H;
    returnValue= e->condition(grille, grille[row][col]);

    if (returnValue)
    {
        switch(returnValue){
        case 1:
            e->selection(grille,grille[row][col],1);
            qqch=true;break;
        case 2:
            e->selection(grille,grille[row][col],2);
            qqch=true;break;
        case 3:
            e->selection(grille,grille[row][col],3);
            qqch=true;break;
        case 4:
            e->selection(grille,grille[row][col],4);
            qqch=true;break;
        case 5:
            e->selection(grille,grille[row][col],5);
            qqch=true;break;
        case 6:
            e->selection(grille,grille[row][col],6);
            qqch=true;break;
        }
    }
    delete e;
    return qqch;
}

bool MainWindow::checkVerThree(int row, int col)
{
    int returnValue;
    bool qqch=false;

    Destroy *e= new Selection3_V;
    returnValue= e->condition(grille, grille[row][col]);

    if (returnValue)
    {
        switch(returnValue){
        case 1:
            e->selection(grille,grille[row][col],1);
            qqch=true;break;
        case 2:
            e->selection(grille,grille[row][col],2);
            qqch=true;break;
        case 3:
            e->selection(grille,grille[row][col],3);
            qqch=true;break;
        case 4:
            e->selection(grille,grille[row][col],4);
            qqch=true;break;
        case 5:
            e->selection(grille,grille[row][col],5);
            qqch=true;break;
        case 6:
            e->selection(grille,grille[row][col],6);
            qqch=true;break;
        }
    }
    delete e;
    return qqch;
}

bool MainWindow::remplirVide()
{
    for (int i=9; i>=0; i--)
    {
        for (int j=9; j>=0; j--)
        {
            if (grille[i][j]->tile==0)
            {
                for (int k=i; k>=0; k--)
                {
                    if (grille[k][j]->tile!=0)
                    {
                        grille[i][j]->tile=grille[k][j]->tile;
                        grille[k][j]->tile=0;
                        break;
                    }
                }
            }
        }
    }
}

bool MainWindow::peuEtreDetruit()
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (checkStar(i, j)==true)
                return true;
        }
    }
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (checkBox(i, j)==true)
                return true;
        }
    }
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (checkLine(i, j)==true)
                return true;
        }
    }
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (checkHorThree(i, j)==true)
                return true;
        }
    }
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (checkVerThree(i, j)==true)
                return true;
        }
    }
    return false;
}

bool MainWindow::cannotPlay()
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (grille[i][j]->tile==5) return false;
        }
    }//check for existing stars

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<9; j++)
        {
            qDebug() << "In check horizontally";
            qDebug() << grille[i][j]->tile;
            int temp=0;
            temp=grille[i][j]->tile;
            grille[i][j]->tile=grille[i][j+1]->tile;
            grille[i][j+1]->tile=temp;
            if (checkVerThree(i,j) || checkHorThree(i,j+1))
            {
                temp=grille[i][j]->tile;
                grille[i][j]->tile=grille[i][j+1]->tile;
                grille[i][j+1]->tile=temp;
            }

            temp=grille[i][j]->tile;
            grille[i][j]->tile=grille[i][j+1]->tile;
            grille[i][j+1]->tile=temp;
            qDebug() << grille[i][j]->tile << "Out check horizontally" ;
        }
    }

    for (int i=0; i<9; i++)
    {
        for (int j=0; j<10; j++)
        {
            qDebug() << "In check vertically";
            qDebug() << grille[i][j]->tile;
            int temp=0;
            temp=grille[i][j]->tile;
            grille[i][j]->tile=grille[i+1][j]->tile;
            grille[i+1][j]->tile=temp;
            if (checkVerThree(i,j)==true)
            {
                grille[i+1][j]->tile=grille[i][j]->tile;
                grille[i][j]->tile=temp;
                qDebug() << "ver" << grille[i][j]->tile;
                return false;
            }
            if (checkHorThree(i,j)==true)
            {
                grille[i+1][j]->tile=grille[i][j]->tile;
                grille[i][j]->tile=temp;
                qDebug() << "hor" << grille[i][j]->tile;
                return false;
            }
            grille[i+1][j]->tile=grille[i][j]->tile;
            grille[i][j]->tile=temp;
            qDebug() <<grille[i][j]->tile << "Out check vertically" ;
        }
    }
    qDebug() << "Cannot play==true";
    return true;
}

void MainWindow::fillInZero()
{
    for (int i=9; i>=0; i--)
    {
        for (int j=9; j>=0; j--)
        {
            if (grille[i][j]->tile==0)
            {
                grille[i][j]->setNumber();
                if (j<=7 && (grille[i][j]->tile==grille[i][j+1]->tile || grille[i][j]->tile==grille[i][j+1]->tile/10) && (grille[i][j]->tile==grille[i][j+2]->tile || grille[i][j]->tile==grille[i][j+2]->tile/10))
                {
                    grille[i][j]->tile=0;
                    j++;
                }//檢查右邊
                if (j>=2 && (grille[i][j]->tile==grille[i][j-1]->tile || grille[i][j]->tile==grille[i][j-1]->tile/10) && (grille[i][j]->tile==grille[i][j-2]->tile || grille[i][j]->tile==grille[i][j-2]->tile/10))
                {
                    grille[i][j]->tile=0;
                    j++;
                }//檢查左邊
                if (i<=7 && (grille[i][j]->tile==grille[i+1][j]->tile || grille[i][j]->tile==grille[i+1][j]->tile/10) && (grille[i][j]->tile==grille[i+2][j]->tile || grille[i][j]->tile==grille[i+2][j]->tile/10))
                {
                    grille[i][j]->tile=0;
                    j++;
                }//檢查下面
                if (j>=1 && j<=8 && (grille[i][j]->tile==grille[i][j-1]->tile || grille[i][j]->tile==grille[i][j-1]->tile/10) && (grille[i][j]->tile==grille[i][j+1]->tile || grille[i][j]->tile==grille[i][j+1]->tile/10))
                {
                    grille[i][j]->tile=0;
                    j++;
                }
            }
        }
    }
}

void MainWindow::refreshCandy()
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            grille[i][j]->setCandy();
        }
    }
}

void MainWindow::resetMap()
{
    qDebug() << "In reset map";

    //Initialize all the blocks
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            grille[i][j]->tile=0;
        }
    }

    for(int i=0; i<10; i++)//row
    {
        for (int j=0; j<10; j++)//column
        {
            grille[i][j]->setNumber();
            grille[i][j]->setCandy();

            if (j>=2 && (grille[i][j]->tile == grille[i][j-2]->tile) && (grille[i][j]->tile == grille[i][j-1]->tile))
            {j--;}

            if (i>=2 && (grille[i][j]->tile == grille[i-2][j]->tile) && (grille[i][j]->tile == grille[i-1][j]->tile))
            {j--;}
        }
    }

    if (cannotPlay()==true){resetMap();}
}


void MainWindow::button_clicked(int R, int C)
{
    qDebug() << grille[R][C]->tile;

    if (!isClicked)
    {
        setClickPicture(grille[R][C]);
        isClicked=true;
        rowBackUp= R;
        colBackUp= C;
    }
    else
    {
        if (rowBackUp==R && colBackUp==C-1)//left
        {
            *grille[rowBackUp][colBackUp]-grille[R][C];
            if (!check(rowBackUp,colBackUp,R,C))
            {
                *grille[R][C]-grille[rowBackUp][colBackUp];
            }
        }
        else if (rowBackUp==R && colBackUp==C+1)//right
        {
            *grille[R][C]-grille[rowBackUp][colBackUp];
            if (!check(rowBackUp,colBackUp,R,C))
            {
                *grille[rowBackUp][colBackUp]-grille[R][C];
            }
        }
        else if (rowBackUp==R-1 && colBackUp==C)//up
        {
            *grille[rowBackUp][colBackUp]|grille[R][C];
            if (!check(rowBackUp,colBackUp,R,C))
            {
                *grille[R][C]|grille[rowBackUp][colBackUp];
            }
        }
        else if (rowBackUp==R+1 && colBackUp==C)//down
        {
            *grille[R][C]|grille[rowBackUp][colBackUp];
            if (!check(rowBackUp,colBackUp,R,C))
            {
                *grille[rowBackUp][colBackUp]|grille[R][C];
            }
        }
        else
        {
            setClickPicture(grille[rowBackUp][colBackUp]);
        }
        isClicked=false;
    }
}

void MainWindow::foo()
{
    while(1)
    {
       remplirVide();
       if (peuEtreDetruit()==false) break;
    }

    fillInZero();
     refreshCandy();
}



void MainWindow::on_restartGame_clicked()
{
    gameStart();
}

void MainWindow::on_quitGame_clicked()
{
    QApplication::quit();
}
