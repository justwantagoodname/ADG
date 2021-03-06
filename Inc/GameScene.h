#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QWidget>
#include<QPainter>
#include<QDebug>
#include<QString>
#include<QTimer>
#include<QKeyEvent>
#include<QDialog>
#include"Mary.h"
#include"Brick.h"
#include"unknown.h"
#include"MushRoom.h"
#include"Master.h"
#include"Pipe.h"
#include"GamePause.h"
#include"MyPushButton.h"
#include"Fire.h"
#include"Castle.h"
#include "Map.h"

class GameScene : public QWidget {
    Q_OBJECT

public:
    explicit GameScene(QWidget *parent = nullptr);

    int timer1;
    int timer2;
    int timer3;
    bool is_kill_timer2;
    bool game_start;
    float time;
    int score;
    bool is_press_x;
    bool is_win;
    QString key;
    Mary *mary;
    Brick *brick;
    Pipe *pipe;
    Unknown *unknown;
    MushRoom *mushroom;
    GamePause *Pause;
    Master *master;
    Fire *fire;
    Castle *castle;
    Map *map;
    ConfigFile *config;

    void paintEvent(QPaintEvent *);//绘图事件
    void keyPressEvent(QKeyEvent *event);//键盘按下
    void keyReleaseEvent(QKeyEvent *event);//键盘抬起
    void timerEvent(QTimerEvent *event);//定时器
    void Game_Init();

    void Die_Init();

    void Pause_Init();

    void Pause_Game_Init();

    void Fall_Down(int &y);

    void Jump_Collision();//角色跳跃碰撞检测
    void Move_Collision();//移动碰撞检测
    void Game_Win();

    signals:
private:

};

#endif // GAMESCENE_H
