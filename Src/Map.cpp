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

}

