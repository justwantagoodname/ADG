#include "MushRoom.h"
#include<QDebug>
MushRoom::MushRoom()
{
    MushRoom_Init();
}


void MushRoom::MushRoom_Init(){
//    mushroom_kind=0;
//    mushroom_x=0;
//    mushroom_y=0;
//    mushroom_state=0;
    mushroom_num = 0;

}

void MushRoom::MushRoom_Move(QVector<QVector<int>>::iterator it, Fire *f, Unknown *u,Brick *r, Mary *m, bool is_bullet){
    unknown = u;
    brick = r;
    mary = m;
    fire = f;
    mushroom_num++;
    this->is_bullet.append(is_bullet);
    mushroom_fall_down_distance.append(19);
    if (is_bullet) {
//        qDebug() << "Hit the bullet";
        mushroom_x.append(*it->begin());
        mushroom_y.append(*(it->begin() + 1));
        mushroom_state.append(1);
        mushroom_kind.append(3);
        return ;
    }
    if(mary->colour==1){
        mushroom_kind.append(1);
    } else {
        mushroom_kind.append(2);
    }
    mushroom_x.append(*it->begin());
    mushroom_y.append(*(it->begin() + 1));
    mushroom_state.append(1);
}

void MushRoom::Move_One(QVector<int>::iterator& it_x, QVector<int>::iterator& it_y,QVector<int>::iterator& it_state, QVector<int>::iterator& it_kind, QVector<int>::iterator it_distance, QVector<bool>::iterator& it_bullet) {
    if (*it_state != 0 && *it_state != -2) {
        if (*it_state <= 20) {
            *it_y -= 2;
            ++*it_state;
        } else if (*it_state > 20) {
            if (*it_bullet) {
                *it_state = -2;
                return;
            } else {
                *it_x += 2;
                ++*it_state;
            }
        }
        for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();it++)
        {
            if (*it->begin() - *it_x >= -50 && *it->begin() - *it_x <= 30 &&
                *(it->begin() + 1) <= *it_y + 40 && *(it->begin() + 1) >= *it_y && *(it->begin() + 2) != 0) {
                return;
            }
        }
        for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it != unknown->m.begin()->end();it++)
        {
            if (*it->begin() - *it_x >= -50 && *it->begin() - *it_x <= 30 &&
                *(it->begin() + 1) <= *it_y + 40 && *(it->begin() + 1) >= *it_y) {
                return;
            }
        }
        *it_state = -1;
        *it_y += 20 - *it_distance;
        --*it_distance;

    }
    if (*it_bullet) {
        if (*it_x - 330 <= mary->x && *it_x - 270 >= mary->x && *it_y - mary->y == 5) {
            *it_state = 0;
            fire->Load_Bullet(5);
            --mushroom_num;
            mushroom_x.erase(it_x);
            mushroom_y.erase(it_y);
            mushroom_state.erase(it_state);
            mushroom_kind.erase(it_kind);
            is_bullet.erase(it_bullet);
            mushroom_fall_down_distance.erase(it_distance);
            return;
        }
    } else {
        if (*it_y >= 460 && *it_state != 0) {
            if (*it_x - 330 <= mary->x && *it_x - 270 >= mary->x && *it_y - mary->y == 5) {
                *it_state = 0;
                mary->colour = *it_kind + 1;
                --mushroom_num;
                mushroom_x.erase(it_x);
                mushroom_y.erase(it_y);
                mushroom_state.erase(it_state);
                mushroom_kind.erase(it_kind);
                is_bullet.erase(it_bullet);
                mushroom_fall_down_distance.erase(it_distance);
                return;
            }
            *it_state = -2;
            *it_y = 460;
            *it_x -= 2;
        }
    }

}

void MushRoom::Move_state(){
    QVector<int>::iterator it_x = mushroom_x.begin(), it_y = mushroom_y.begin(), it_state = mushroom_state.begin(), it_kind = mushroom_kind.begin(), it_distance = mushroom_fall_down_distance.begin();
    QVector<bool>::iterator it_bullet = is_bullet.begin();
    for (int i = 0;i < mushroom_num; i++) {
//        qDebug() << i;
        Move_One(it_x, it_y, it_state, it_kind, it_distance, it_bullet);
        ++it_x;
        ++it_y;
        ++it_state;
        ++it_kind;
        ++it_distance;
        ++it_bullet;
    }
}
