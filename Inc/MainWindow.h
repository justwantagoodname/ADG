//
// Created by SamChen on 2022/4/13.
//

#ifndef AGD_MAINWINDOW_H
#define AGD_MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include "Ui_MainWindow.h"
#include "MyPushButton.h"
#include "GameScene.h"
#include "GameHelp.h"

QT_BEGIN_NAMESPACE
namespace ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    void paintEvent(QPaintEvent *);

    Ui::MainWindow *ui;
};

#endif //AGD_MAINWINDOW_H
