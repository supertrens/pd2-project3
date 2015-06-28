#ifndef GRILLE
#define GRILLE


#include <QObject>
#include <QPushButton>
#include <QLabel>

#define N 10

class Grille : public QObject
{
    Q_OBJECT
public:
    explicit Grille (QWidget *parent, int Row, int Col);
    ~Grille();
    QTimer * time;
    QPushButton * button;


    void setNumber();  //setRandomNumber
    void setCandy();   //setBottomPicture
    void operator -(Grille * grille);
    void operator |(Grille * grille);

    int       tile;
    const int row;
    const int col;


signals:
    void Click(int row,int col);
    void moveDone();

public slots:
    void click();
    void moveRight();
    void moveLeft();
    void moveDown();
    void moveUp();

private:
    int deplacer;

};

#endif // GRILLE

