#include "mushroom.h"
#include<QDebug>
MushRoom::MushRoom()
{
    MushRoom_Init();
}


void MushRoom::MushRoom_Init(){
    mushroom_kind=0;
    mushroom_x=0;
    mushroom_y=0;
    mushroom_state=0;
    mushroom_fall_down_distance=19;

}

void MushRoom::MushRoom_Move(QVector<QVector<int>>::iterator it, Fire *f, Unknown *u,Brick *r, Mary *m, bool is_bullet){
    unknown = u;
    brick = r;
    mary = m;
    fire = f;
    this->is_bullet = is_bullet;
    if (is_bullet) {
        qDebug() << "Hit the bullet";
        mushroom_x = *it->begin();
        mushroom_y = *(it->begin() + 1);
        mushroom_state = 1;
        return ;
    }
    if(mary->colour==1){
        mushroom_kind = 1;
    } else {
        mushroom_kind = 2;
    }
    mushroom_x = *it->begin();
    mushroom_y = *(it->begin() + 1);
    mushroom_state = 1;
}

void MushRoom::Move_state(){
    if (mushroom_state != 0 && mushroom_state != -2) {
        if (mushroom_state <= 20) {
            mushroom_y -= 2;
            mushroom_state++;
        } else if (mushroom_state > 20) {
            mushroom_x += 2;
            mushroom_state++;
        }
        for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();it++)
        {
            if (*it->begin() - mushroom_x >= -50 && *it->begin() - mushroom_x <= 30 &&
                *(it->begin() + 1) <= mushroom_y + 40 && *(it->begin() + 1) >= mushroom_y && *(it->begin() + 2) != 0) {
                return;
            }
        }
        for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it != unknown->m.begin()->end();it++)
        {
            if (*it->begin() - mushroom_x >= -50 && *it->begin() - mushroom_x <= 30 &&
                *(it->begin() + 1) <= mushroom_y + 40 && *(it->begin() + 1) >= mushroom_y) {
                return;
            }
        }
        mushroom_state = -1;
        mushroom_y += 20 - mushroom_fall_down_distance;
        mushroom_fall_down_distance--;

    }
    if (mushroom_y >= 460 && mushroom_state != 0) {
        if (mushroom_x - 330 <= mary->x && mushroom_x - 270 >= mary->x && mushroom_y - mary->y == 5) {
            mushroom_state = 0;
            if (is_bullet) {
                qDebug() << fire->bullet ;
                fire->Load_Bullet(5);
            } else {
                mary->colour = mushroom_kind + 1;
            }
            mushroom_fall_down_distance = 19;
            return;
        }
        mushroom_state = -2;
        mushroom_y = 460;
        mushroom_x -= 2;
    }
}
