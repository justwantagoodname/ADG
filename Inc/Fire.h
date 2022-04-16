#ifndef FIRE_H
#define FIRE_H

#include"Mary.h"
#include"Pipe.h"
#include"Brick.h"
#include"Master.h"

class Fire {
public:
//    int x, y, direction;
//    int x1, y1, direction1;
//    int x2, y2, direction2;
//    bool is_have;
//    bool is_have1;
//    bool is_have2;
//    bool is_fire_max;
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
