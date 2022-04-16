#ifndef FIRE_H
#define FIRE_H

#include"Mary.h"
#include"Pipe.h"
#include"Brick.h"
#include"Master.h"

class Fire {
public:
    QVector<int> bullet_x;
    QVector<int> bullet_y;
    QVector<int> bullet_direction;
    int bullet;
    int bullet_num;
    Mary *mary;
    Pipe *pipe;
    Brick *brick;
    Master *master;

    Fire();
    void Fire_Init();
    void Fire_Move(Mary *m, Pipe *p, Brick *r, Master *ms);
    void Fire_xy();
    void Fire_state();
};

#endif // FIRE_H
