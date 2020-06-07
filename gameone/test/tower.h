#ifndef TOWER_H
#define TOWER_H
#include<QPainter>
#include<QLabel>
class Tower
{
public:
    Tower(QPoint pos,int n,const QPixmap &sprite=QPixmap("E:/gameone/tower4.gif"));
QPoint m_pos;
    void draw(QLabel **towerlabel,QMovie *pic) const;

   int no;
private:

    int m_attackrange;
    int m_damage;
    int m_firerate;
    QPixmap m_sprite;

};

#endif // TOWER_H
