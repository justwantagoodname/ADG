//
// Created by SamChen on 2022/4/13.
//

#include <QTimer>

#include "GameHelp.h"
#include "MyPushButton.h"

GameHelp::GameHelp(QWidget *parent) : QWidget(parent) {
    setWindowTitle("游戏帮助");
    resize(800, 550);
    MyPushButton *back_btn = new MyPushButton(":/Res/back.png");//设置帮助按钮
    back_btn->setParent(this);
    back_btn->setFixedSize(180, 80);
    back_btn->setIconSize(QSize(180, 80));
    back_btn->move(500, this->height() * 0.8);
    connect(back_btn, &QPushButton::clicked, [=]() {
        back_btn->zoom1();
        back_btn->zoom2();
        QTimer::singleShot(500, this, [=]() {
            this->close();
            emit
            this->back();
        });
    });
}

void GameHelp::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, 800, 550, QPixmap(":/Res/gamehelp.png"));
}