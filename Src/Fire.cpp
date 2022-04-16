#include "Fire.h"
#include<QDebug>

Fire::Fire() {
    Fire_Init();
}

void Fire::Fire_Init() {
    bullet = 0;
    bullet_num = 0;
}

void Fire::Fire_Move(Mary *m, Pipe *p, Brick *r, Master *ms) {
    mary = m;
    pipe = p;
    brick = r;
    master = ms;
}

void Fire::Fire_xy() {
    if (bullet > 0) {
        --bullet;
        if (mary->direction == "right") {
            bullet_x.append(mary->x + 350);
            bullet_direction.append(1);
        } else {
            bullet_x.append(mary->x + 290);
            bullet_direction.append(0);
        }
        bullet_y.append(mary->y + 15);
        if (mary->x <= 300) {
            bullet_x[bullet_num] -= 300 - mary->x;
        }
        ++bullet_num;
    }
}

int count = 0;

void Fire::Fire_state() {
    for (int i = 0; i < bullet_num; ++i) {
        if (bullet_direction[i] == 1) {
            bullet_x[i] += 10;
        } else {
            bullet_x[i] -= 10;
        }
    }
    for (QVector < QVector < int >> ::iterator it = master->m.begin()->begin(); it != master->m.begin()->end();
    it++)
    {
        QVector<int>::iterator itx = bullet_x.begin(), ity = bullet_y.begin(), itd = bullet_direction.begin();
        while (itx != bullet_x.end() && ity != bullet_y.end()) {
            if (*itx > *it->begin() && *itx <= *it->begin() + 30 && *(it->begin() + 2) == 1&& *ity > *(it->begin() + 1) && *ity <= *(it->begin() + 1) + 40) {
                bullet_x.erase(itx);
                bullet_y.erase(ity);
                bullet_direction.erase(itd);
                *(it->begin() + 2) = 0;
                --bullet_num;
                return;
            }
            ++itx;
            ++ity;
            ++itd;
        }
    }
    for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();
    it++)
    {
        QVector<int>::iterator itx = bullet_x.begin(), ity = bullet_y.begin(), itd = bullet_direction.begin();
        while (itx != bullet_x.end() && ity != bullet_y.end()) {
            if (*itx > *it->begin() + 10 && *itx <= *it->begin() + 30 && *ity > *(it->begin() + 1) && *ity <= *(it->begin() + 1) + 40) {
                bullet_x.erase(itx);
                bullet_y.erase(ity);
                bullet_direction.erase(itd);
                --bullet_num;
                return;
            }
            ++itx;
            ++ity;
            ++itd;
        }
    }

    for (QVector < QVector < int >> ::iterator it = pipe->long_m.begin()->begin(); it != pipe->long_m.begin()->end();
    it++)
    {
        QVector<int>::iterator itx = bullet_x.begin(), ity = bullet_y.begin(), itd = bullet_direction.begin();
        while (itx != bullet_x.end() && ity != bullet_y.end()) {
            if (*itx > *it->begin() + 10 && *itx <= *it->begin() + 30 && *ity > *(it->begin() + 1) && *ity <= *(it->begin() + 1) + 100) {
                bullet_x.erase(itx);
                bullet_y.erase(ity);
                bullet_direction.erase(itd);
                --bullet_num;
                return;
            }
            ++itx;
            ++ity;
            ++itd;
        }
    }
    for (QVector < QVector < int >> ::iterator it = pipe->short_m.begin()->begin(); it != pipe->short_m.begin()->end();
    it++)
    {
        QVector<int>::iterator itx = bullet_x.begin(), ity = bullet_y.begin(), itd = bullet_direction.begin();
        while (itx != bullet_x.end() && ity != bullet_y.end()) {
            if (*itx > *it->begin() + 10 && *itx <= *it->begin() + 30 && *ity > *(it->begin() + 1) && *ity <= *(it->begin() + 1) + 50) {
                bullet_x.erase(itx);
                bullet_y.erase(ity);
                bullet_direction.erase(itd);
                --bullet_num;
                return;
            }
            ++itx;
            ++ity;
            ++itd;
        }
    }
}

void Fire::Load_Bullet(int num) {
    bullet += num;
}