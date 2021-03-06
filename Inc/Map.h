//
// Created by null on 22-4-17.
//

#ifndef AGD_MAP_H
#define AGD_MAP_H
#include <QObject>
#include "Config.h"
#include "unknown.h"
#include "Brick.h"
#include "Castle.h"
#include "Master.h"

class Map: public QObject{
Q_OBJECT;
    ConfigFile *map;
public:
    Map(QJsonObject *maps, QObject *parent = nullptr);
    ~Map();
    void Map_Init(Unknown *unknown, Brick *brick, Castle *castle, Master *master, Pipe *pipe);
};
#endif //AGD_MAP_H
