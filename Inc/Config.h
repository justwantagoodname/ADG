//
// Created by null on 2022/4/13.
//

#ifndef AGD_CONFIG_H
#define AGD_CONFIG_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QFile>

class ConfigUtils : public QObject {
    Q_OBJECT;
private:
    QJsonParseError *err;
    QJsonDocument *doc_root;
public:
    ConfigUtils();
    ConfigUtils(QByteArray& json_byte_arr): ConfigUtils() {
        parseJson(json_byte_arr);
    }
    ~ConfigUtils();
    bool parseJson(QByteArray array);
    QJsonObject getConfigRoot();
    QJsonValue getConfig(QString key);
};

class ConfigFile : public ConfigUtils{
    Q_OBJECT;
private:
    QFile *config_file;
public:
    ConfigFile();
    ConfigFile(const QString& file_path);
    ~ConfigFile();
    bool readFile(const QString &file_path);
};
#endif //AGD_CONFIG_H
