#include "MushRoom.h"
#include<QDebug>
MushRoom::MushRoom()
{
    MushRoom_Init();
}


void MushRoom::MushRoom_Init(){
<<<<<<< Updated upstream
    mushroom_kind=0;
    mushroom_x=0;
    mushroom_y=0;
    mushroom_state=0;
    mushroom_fall_down_distance=19;
=======
//    mushroom_kind=0;
//    mushroom_x=0;
//    mushroom_y=0;
//    mushroom_state=0;
    mushroom_num = 0;
>>>>>>> Stashed changes

}

void MushRoom::MushRoom_Move(QVector<QVector<int>>::iterator it,Unknown *u,Brick *r, Mary *m, bool is_bullet){
    unknown = u;
    brick = r;
    mary = m;
    if (is_bullet) {
        qDebug() << "Hit the bullet";
<<<<<<< Updated upstream
=======
        mushroom_x.append(*it->begin());
        mushroom_y.append(*(it->begin() + 1));
        mushroom_state.append(1);
        mushroom_kind.append(3);
        mushroom_fall_down_distance.append(19);
>>>>>>> Stashed changes
        return ;
    }
    if(mary->colour==1){
        mushroom_kind = 1;
    } else {
        mushroom_kind = 2;
    }
<<<<<<< Updated upstream
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
            mary->colour = mushroom_kind + 1;
            mushroom_fall_down_distance = 19;
            return;
        }
        mushroom_state = -2;
        mushroom_y = 460;
        mushroom_x -= 2;
=======
    mushroom_x.append(*it->begin());
    mushroom_y.append(*(it->begin() + 1));
    mushroom_state.append(1);
    mushroom_fall_down_distance.append(19);
}

void MushRoom::Move_state(){
    QVector<int>::iterator it_x = mushroom_x.begin(), it_y = mushroom_y.begin(), it_state = mushroom_state.begin(), it_kind = mushroom_kind.begin(), it_bullet = is_bullet.begin(), it_distance = mushroom_fall_down_distance.begin();
    while (it_x != mushroom_x.end()) {
        if (*it_state != 0 && *it_state != -2) {
            if (*it_state <= 20) {
                *it_y -= 2;
                *it_state++;
            } else if (*it_state > 20) {
                *it_x += 2;
                *it_state++;
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
            *it_distance--;

        }
        if (*it_y >= 460 && *it_state != 0) {
            if (*it_x - 330 <= mary->x && *it_x - 270 >= mary->x && *it_y - mary->y == 5) {
                *it_state = 0;
                if (*it_bullet) {
                    fire->Load_Bullet(5);
                } else {
                    mary->colour = *it_kind + 1;
                }
                --mushroom_num;
                mushroom_state.erase(it_state);
                mushroom_x.erase(it_x);
                mushroom_y.erase(it_y);
                mushroom_kind.erase(it_kind);
                is_bullet.erase(it_bullet);
                mushroom_fall_down_distance.erase(it_distance);
                return;
            }
            *it_state = -2;
            *it_y = 460;
            *it_x -= 2;
        }
        ++it_x;
        ++it_y;
        ++it_state;
        ++it_kind;
        ++it_bullet;
        ++it_distance;
>>>>>>> Stashed changes
    }
}
