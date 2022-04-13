//
// Created by SamChen on 2022/4/13.
//

#ifndef AGD_GAMEHELP_H
#define AGD_GAMEHELP_H

#include <QMainWindow>
#include <QWidget>
#include<QPainter>

class GameHelp : public QWidget {
Q_OBJECT
public:
    explicit GameHelp(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:
    void back();
};


#endif //AGD_GAMEHELP_H
