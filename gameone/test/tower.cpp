#include "tower.h"
#include<QMovie>
#include<QLabel>
Tower::Tower(QPoint pos,int n, const QPixmap &sprite):m_pos(pos),m_sprite(sprite){
    m_attackrange=100;
    m_firerate=1000;
    m_damage=10;

    no=n;
}
void Tower::draw(QLabel **towerlabel,QMovie *pic) const{
towerlabel[no]->setGeometry(m_pos.x()-20,m_pos.y()-75,50,84);
towerlabel[no]->setScaledContents(true);
towerlabel[no]->setMovie(pic);
pic->start();
}
