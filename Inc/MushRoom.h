#ifndef MUSHROOM_H
#define MUSHROOM_H
#include<QVector>
#include<QMap>
#include"Brick.h"
#include"unknown.h"
#include"Mary.h"
class MushRoom
{
public:
    QMap<int,QVector<QVector<int>>>m;
<<<<<<< Updated upstream
    int mushroom_kind;
    int mushroom_x;
    int mushroom_y;
    int mushroom_state;
    int mushroom_fall_down_distance;
    int is_bullet;
=======
    QVector<int> mushroom_kind;
    QVector<int> mushroom_x;
    QVector<int> mushroom_y;
    QVector<int> mushroom_state;
    QVector<int> is_bullet;
    QVector<int> mushroom_fall_down_distance;
    int mushroom_num;

>>>>>>> Stashed changes
    Brick *brick;
    Unknown *unknown;
    Mary *mary;
    MushRoom();
    void MushRoom_Init();
    void Move_state();
    void MushRoom_Move(QVector<QVector<int>>::iterator it,Unknown *u,Brick *r, Mary *m, bool is_bullet);
};

#endif // MUSHROOM_H
