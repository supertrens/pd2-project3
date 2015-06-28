#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "grille.h"
#include "destroy.h"

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void startGame();
    void setCandySelected( Grille *grille); //setClickedPicture
    bool Check    (int row1,int col1,int row2,int col2);
    bool Check5_V (int row,int col);
    bool Check5_H  (int row,int col);
    bool Check4_V (int row,int col);
    bool Check4_H (int row,int col);
    bool Check3_V (int row,int col);
    bool Check3_H (int row,int col);

    void refreshCandy();  //renew picture
    void remplirVide();  //MoveFillZero
    bool effacerLesPossibilites(); // EliminateLeftPOssiblity
    void selectionApresElimination(); //SpawnAfterEliminate


public slots:
    void candySelected( int row , int col);
    void foo();

private:
    Ui::MainWindow *ui;

    Grille * grille[N][N];
    Destroy * destroy;
    bool isSelected ;
    int rowBackUp ;
    int colBackUp ;
};

#endif // MAINWINDOW_H
