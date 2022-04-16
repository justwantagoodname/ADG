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
    mushroom_fall_down_distance=19;

}

void MushRoom::MushRoom_Move(QVector<QVector<int>>::iterator it, Fire *f, Unknown *u,Brick *r, Mary *m, bool is_bullet){
    unknown = u;
    brick = r;
    mary = m;
    fire = f;
    mushroom_num++;
    this->is_bullet.append(is_bullet);
    if (is_bullet) {
        qDebug() << "Hit the bullet";
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

void MushRoom::Move_state(){
    for (int i = 0;i < mushroom_num; i++) {
        if (mushroom_state[i] != 0 && mushroom_state[i] != -2) {
            if (mushroom_state[i] <= 20) {
                mushroom_y[i] -= 2;
                mushroom_state[i]++;
            } else if (mushroom_state[i] > 20) {
                mushroom_x[i] += 2;
                mushroom_state[i]++;
            }
            for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();it++)
            {
                if (*it->begin() - mushroom_x[i] >= -50 && *it->begin() - mushroom_x[i] <= 30 &&
                    *(it->begin() + 1) <= mushroom_y[i] + 40 && *(it->begin() + 1) >= mushroom_y[i] && *(it->begin() + 2) != 0) {
                    return;
                }
            }
            for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it != unknown->m.begin()->end();it++)
            {
                if (*it->begin() - mushroom_x[i] >= -50 && *it->begin() - mushroom_x[i] <= 30 &&
                    *(it->begin() + 1) <= mushroom_y[i] + 40 && *(it->begin() + 1) >= mushroom_y[i]) {
                    return;
                }
            }
            mushroom_state[i] = -1;
            mushroom_y[i] += 20 - mushroom_fall_down_distance;
            mushroom_fall_down_distance--;

        }
        if (mushroom_y[i] >= 460 && mushroom_state[i] != 0) {
            if (mushroom_x[i] - 330 <= mary->x && mushroom_x[i] - 270 >= mary->x && mushroom_y[i] - mary->y == 5) {
                mushroom_state[i] = 0;
                if (is_bullet[i]) {
                    mushroom_num--;
                    fire->Load_Bullet(5);
                } else {
                    mary->colour = mushroom_kind[i] + 1;
                }
                mushroom_fall_down_distance = 19;
                return;
            }
            mushroom_state[i] = -2;
            mushroom_y[i] = 460;
            mushroom_x[i] -= 2;
        }
    }
}
