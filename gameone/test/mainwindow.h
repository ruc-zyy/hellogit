#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "enemy.h"
#include <QMainWindow>
#include <towerposition.h>
#include <tower.h>
#include <QPainter>
#include <QMovie>
#include <waypoint.h>
#include <QTimer>
class Enemy;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);
    bool canBuyTower() const;
    void drawtower();
    QLabel *towerlabel[21]={new QLabel(this)};
    QList<QLabel *> t;
    QMovie *pic=new QMovie("E:/gameone/tower4.gif");
int numoftower=0;

QList<WayPoint *> m_wayPointsList;	// 在paintEvent中需要进行绘制，那个类似的foreach(xxx) xxx.draw(xxx)

void addWayPoints();			// 在构造函数中调用

QList<Enemy *> m_enemyList;
void getHpDamage(int damege=1){}
void removedEnemy(Enemy *enemy){}
bool loadWave();
QTimer *timer = new QTimer(this);

QLabel *enemylabel[50]={new QLabel(this)};
QList<QLabel *> e;
QMovie *epic=new QMovie("E:/gameone/wolf.gif");
int numofwolf=0;
protected:
    void paintEvent(QPaintEvent *);
protected slots:
 void updateMap();
private:
    Ui::MainWindow *ui;
    QList<TowerPosition> m_towerPositionsList;
    void loadTowerPositions();
    QList<Tower> m_towersList;
    int m_waves=0;

};

#endif // MAINWINDOW_H
