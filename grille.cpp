#include "grille.h"
#include <QDebug>
#include <QTimer>

#define NUM_COOKIE 4

Grille::Grille(QWidget *parent, int Row, int Col) : QObject(parent),
    row(Row),col(Col),deplacer(1)
{
    button = new QPushButton(parent);
    time   = new QTimer();
    //button->setFlat(true);
    //clicked=false;
    connect(button,SIGNAL(clicked()),this,SLOT(click()));
     button->setGeometry((col)*50,(row)*50,50,50);
    //button->setIconSize(button->size());
}

Grille::~Grille()
{
    delete button;
}

//Method to randomly select a cookie
void Grille::setNumber()
{
    tile = rand()% NUM_COOKIE + 1;
    return;
}


void Grille::setCandy()
{
    // 1 red, 2 yellow, 3 green, 4 blue
    switch(tile){
        case 1:
            button->setIcon(QIcon(QPixmap(":/pic/Cupcake.png")));
            break;
        case 11:
            button->setIcon(QIcon(QPixmap(":/pic/red_vertical_bomb.png")));
            break;
        case 12:
            button->setIcon(QIcon(QPixmap(":/pic/red_horizontal_bomb.png")));
            break;
        case 13:
            button->setIcon(QIcon(QPixmap(":/pic/red_bomb.png")));
            break;
        case 2:
            button->setIcon(QIcon(QPixmap(":/pic/Croissant.png")));
            break;
        case 21:
            button->setIcon(QIcon(QPixmap(":/pic/yellow_vertical_bomb.png")));
            break;
        case 22:
            button->setIcon(QIcon(QPixmap(":/pic/yellow_horizontal_bomb.png")));
            break;
        case 23:
            button->setIcon(QIcon(QPixmap(":/pic/yellow_bomb.png")));
            break;
        case 3:
            button->setIcon(QIcon(QPixmap(":/pic/Macaroon.png")));
            break;
        case 31:
            button->setIcon(QIcon(QPixmap(":/pic/green_vertical_bomb.png")));
            break;
        case 32:
            button->setIcon(QIcon(QPixmap(":/pic/green_horizontal_bomb.png")));
            break;
        case 33:
            button->setIcon(QIcon(QPixmap(":/pic/green_bomb.png")));
            break;
        case 4:
            button->setIcon(QIcon(QPixmap(":/pic/Donut.png")));
            break;
        case 41:
            button->setIcon(QIcon(QPixmap(":/pic/blue_vertical_bomb.png")));
            break;
        case 42:
            button->setIcon(QIcon(QPixmap(":/pic/blue_horizontal_bomb.png")));
            break;
        case 43:
            button->setIcon(QIcon(QPixmap(":/pic/blue_bomb.png")));
            break;
        case 5:
            button->setIcon(QIcon(QPixmap(":/pic/power_bomb.png")));
            break;
        default:
            button->setIcon(QIcon(QPixmap("NO PICTURE")));
    }
    return;
}

void Grille::operator-(Grille *grille)
{
    int tmp = tile;
    tile = grille->tile;
    grille->tile=tmp;
    connect(time,SIGNAL(timeout()),this,SLOT(moveRight()));
    connect(grille->time,SIGNAL(timeout()),grille,SLOT(moveLeft()));
    time->start(100);
    grille->time->start(100);
}

void Grille::operator |(Grille *grille)
{
    int tmp = tile;
    tile = grille->tile;
    grille->tile= tmp;
    connect(time,SIGNAL(timeout()),this,SLOT(moveDown()));
    connect(grille->time,SIGNAL(timeout()), grille , SLOT(moveUp()));
    time->start(100);
    grille->time->start(100);
    return;
}

void Grille::click()
{
    emit Click(row,col);
}

void Grille::moveRight()
{
    button->setGeometry(col*50 + deplacer*10 , row*50 ,50,50);
    deplacer++;
    if(deplacer > 5){
        deplacer = 1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveRight()));
        button->setGeometry(col*50,row*50,50,50);

        setCandy();
        //time->stop();
        emit moveDone();
    }
    return;
}

void Grille::moveLeft()
{
    button->setGeometry(col*50- deplacer *10,row*50,50,50);
    deplacer++;
    if(deplacer > 5){
        deplacer = 1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveLeft()));
        button->setGeometry(col*50,row*50,50,50);
        setCandy();
        //time->stop();
        //emit MoveDone();
    }
    return;
}

void Grille::moveDown()
{
    button->setGeometry(col*50 , row*50 + deplacer*10 , 50, 50);
    deplacer++;
    if(deplacer > 5)
    {
        deplacer=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveDown()));
        button->setGeometry(col*50,row*50,50,50);
        setCandy();
        //time->stop();
        emit moveDone();
    }
    return;
}

void Grille::moveUp()
{
    button->setGeometry(col*50,row*50-deplacer*10,50,50);
    deplacer++;
    if(deplacer>5){
        deplacer=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveUp()));
        button->setGeometry(col*50,row*50,50,50);
        setCandy();
        //time->stop();
        //emit MoveDone();
    }
    return;
}
