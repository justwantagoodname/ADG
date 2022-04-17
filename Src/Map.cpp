//
// Created by null on 22-4-17.
//

#include "Map.h"
#include "Brick.h"
#include "Castle.h"
#include "Master.h"
#include "Pipe.h"

Map::Map(QJsonObject *maps, QObject *parent): QObject(parent) {
//    qDebug() << "Read" << maps->value("1").toString();
    map = new ConfigFile(maps->value("1").toString());
}

Map::~Map() noexcept {
    delete map;
}

void Map::Map_Init(Unknown *unknown, Brick *brick, Castle *castle, Master *master, Pipe *pipe) {
   auto objects = map->getConfig("data").toObject();
   auto unknown_map = objects.value("unknown").toArray();
   QVector<QVector<int> > v2;
   QVector<int> v;

   for (const auto &item : unknown_map) {
       for (const auto &data : item.toArray()) {
           v.push_back(data.toInt());
       }
       v2.push_back(v);
       v.clear();
   }
   unknown->m.insert(1, v2);

   v2.clear();
   auto  brick_map = objects.value("brick").toArray();
    for (const auto &item : brick_map) {
        for (const auto &data : item.toArray()) {
            v.push_back(data.toInt());
        }
        v.push_back(1);
//        qDebug() << v;
        v2.push_back(v);
        v.clear();
    }
//    qDebug() << v2;
    brick->m.insert(1, v2);

    v2.clear();
    auto  castle_map = objects.value("castle").toArray();
    for (const auto &item : castle_map) {
        for (const auto &data : item.toArray()) {
            v.push_back(data.toInt());
        }
//        qDebug() << v;
        v2.push_back(v);
        v.clear();
    }
    castle->m.insert(1, v2);

    v2.clear();
    auto master_map = objects.value("master").toArray();
    for (const auto &item : master_map) {
        for (const auto &data : item.toArray()) {
            v.push_back(data.toInt());
        }
        v.push_back(1);
        v.push_back(0);
        v.push_back(0);
//        qDebug() << v;
        v2.push_back(v);
        v.clear();
    }
    master->m.insert(1, v2);

    v2.clear();
    auto pipe_map = objects.value("long_pipe").toArray();
    for (const auto &item : pipe_map) {
        for (const auto &data : item.toArray()) {
            v.push_back(data.toInt());
        }
//        qDebug() << v;
        v2.push_back(v);
        v.clear();
    }
    pipe->long_m.insert(1,v2);

    v2.clear();
    pipe_map = objects.value("short_pipe").toArray();
    for (const auto &item : pipe_map) {
        for (const auto &data : item.toArray()) {
            v.push_back(data.toInt());
        }
//        qDebug() << v;
        v2.push_back(v);
        v.clear();
    }
    pipe->short_m.insert(1, v2);
}

