#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enemy.h"
#include <QPainter>
#include <towerposition.h>
#include <QMouseEvent>
#include <QMovie>
#include <QLabel>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)

{
    ui->setupUi(this);


for(int i=0;i<=20;i++){
    towerlabel[i]=new QLabel(this);
}
for(int i=0;i<=49;i++){
    enemylabel[i]=new QLabel(this);
}
addWayPoints();
loadWave();


connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));
timer->start(30);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap("E:/gameone/map2.png"));
    loadTowerPositions();
    for(int i=0;i<m_towerPositionsList.size();i++){
        m_towerPositionsList[i].draw(&painter);

    }


foreach(Tower tower,m_towersList){


tower.draw(towerlabel,pic);

}


foreach(Enemy *enemy,m_enemyList){
    enemy->draw(&painter,enemylabel,epic);
}

}

void MainWindow::loadTowerPositions(){
    QPoint pos[] =	{

        QPoint(320, 90),
        QPoint(470, 90),
        QPoint(550, 90),
        QPoint(160, 250),
        QPoint(320, 250),
        QPoint(480, 250),
        QPoint(700, 250),
        QPoint(170, 390),

        QPoint(550, 390),
        QPoint(320, 480),
        QPoint(400, 550),
        QPoint(620, 550),
        QPoint(170, 620),

                    };
    int len	= sizeof(pos) / sizeof(pos[0]);
    for (int i = 0; i < len; ++i) m_towerPositionsList.push_back(pos[i]);

}

void MainWindow::mousePressEvent(QMouseEvent *event)

{

    QPoint pressPos=event->pos();

    auto it = m_towerPositionsList.begin();

    while (it != m_towerPositionsList.end())

    {

        if (canBuyTower() && it->containPoint(pressPos) && !it->hasTower())

        {

            it->setHasTower();


numoftower=numoftower+1;
            m_towersList.push_back(Tower(it->centerPos(),numoftower));

            update();

            break;

        }



        ++it;

    }

}



bool MainWindow::canBuyTower() const

{

    return true;

}

void MainWindow::addWayPoints()

{

    WayPoint *wayPoint1 = new WayPoint(QPoint(120, 340));

    m_wayPointsList.push_back(wayPoint1);



    WayPoint *wayPoint2 = new WayPoint(QPoint(270, 340));

    m_wayPointsList.push_back(wayPoint2);

    wayPoint2->setNextWayPoint(wayPoint1);



    WayPoint *wayPoint3 = new WayPoint(QPoint(270, 650));

    m_wayPointsList.push_back(wayPoint3);

    wayPoint3->setNextWayPoint(wayPoint2);



    WayPoint *wayPoint4 = new WayPoint(QPoint(730, 650));

    m_wayPointsList.push_back(wayPoint4);

    wayPoint4->setNextWayPoint(wayPoint3);



    WayPoint *wayPoint5 = new WayPoint(QPoint(730, 505));

    m_wayPointsList.push_back(wayPoint5);

    wayPoint5->setNextWayPoint(wayPoint4);



    WayPoint *wayPoint6 = new WayPoint(QPoint(433, 505));

    m_wayPointsList.push_back(wayPoint6);

    wayPoint6->setNextWayPoint(wayPoint5);



    WayPoint *wayPoint7 = new WayPoint(QPoint(433, 340));

    m_wayPointsList.push_back(wayPoint7);

    wayPoint7->setNextWayPoint(wayPoint6);


    WayPoint *wayPoint8 = new WayPoint(QPoint(650, 340));

    m_wayPointsList.push_back(wayPoint8);

    wayPoint8->setNextWayPoint(wayPoint7);


    WayPoint *wayPoint9 = new WayPoint(QPoint(650, 195));

    m_wayPointsList.push_back(wayPoint9);

    wayPoint9->setNextWayPoint(wayPoint8);


    WayPoint *wayPoint10 = new WayPoint(QPoint(150, 195));

    m_wayPointsList.push_back(wayPoint10);

    wayPoint10->setNextWayPoint(wayPoint9);
}


bool MainWindow::loadWave()

{

    if (m_waves >= 6)

        return false;

    WayPoint *startWayPoint = m_wayPointsList.back(); // 这里是个逆序的，尾部才是其实节点

    int enemyStartInterval[] = { 100, 2000, 4000, 6000, 8000, 10000 };

    for (int i = 0; i < 6; ++i)

    {
numofwolf++;
        Enemy *enemy = new Enemy(numofwolf,startWayPoint, this);

        m_enemyList.push_back(enemy);

        QTimer::singleShot(enemyStartInterval[i], enemy, SLOT(doActivate()));

    }

    return true;

}


void MainWindow::updateMap()

{

    foreach (Enemy *enemy, m_enemyList)

        enemy->move();

    update();

}
