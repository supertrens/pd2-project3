#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <ctime>
#include <cstdlib>
#include <QString>

#include "grille.h"
#include "destroy.h"
#include "selection5_v.h"
#include "selection4_v.h"
#include "selection3_v.h"
#include "selection3_h.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool isClicked=false;
    int rowBackUp;
    int colBackUp;
    int score;
    int step;

    void gameStart();
    void setClickPicture(Grille *grille);
    bool check(int row1, int col1,int row2, int col2);//find the blocks to destroy
    bool checkDoubleStar(int row1, int col1,int row2, int col2);
    bool checkBombStar(int row1, int col1,int row2, int col2);
    bool checkOneStar(int row1, int col1,int row2, int col2);
    bool checkStar(int row, int col);
    bool checkBox(int row, int col);
    bool checkLine(int row, int col);
    bool checkHorThree(int row, int col);
    bool checkVerThree(int row, int col);

    bool remplirVide();//Remplir Vide
    bool peuEtreDetruit();//effacerLesPossibilites
    bool cannotPlay();//
    void fillInZero();//selectionApresElimination
    void refreshCandy();
    void resetMap();


    QString score_str;
    QString step_str;

private:
    Ui::MainWindow *ui;
    Grille *grille[10][10];
    Destroy *e;

public slots:
    void button_clicked(int row, int col);
    void foo();

private slots:

    void on_restartGame_clicked();
    void on_quitGame_clicked();
};

#endif // MAINWINDOW_H
