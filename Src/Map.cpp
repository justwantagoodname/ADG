//
// Created by null on 22-4-17.
//

#include "Map.h"

Map::Map(QJsonObject *maps, QObject *parent): QObject(parent) {
//    qDebug() << "Read" << maps->value("1").toString();
    map = new ConfigFile(maps->value("1").toString());
}

Map::~Map() noexcept {
    delete map;
}

void Map::Map_Init(Unknown *unknown) {
   auto objects = map->getConfig("data").toObject();
   auto unknown_map = objects.value("unknown").toArray();
   QVector<QVector<int> > v2;
   QVector<int> v;
   for (const auto &item : unknown_map) {
//       qDebug() << item;
       for (const auto &data : item.toArray()) {
           v.push_back(data.toInt());
       }
       v2.push_back(v);
       v.clear();
   }
   unknown->m.insert(1, v2);
}

