//
// Created by null on 2022/4/13.
//

#include "Config.h"

ConfigUtils::ConfigUtils() {
    doc_root = new QJsonDocument;
    err = new QJsonParseError;
}

ConfigUtils::~ConfigUtils() {
    delete doc_root;
    delete err;
}

bool ConfigUtils::parseJson(QByteArray json) {
    *doc_root = QJsonDocument::fromJson(json, err);

    if (err->error != QJsonParseError::NoError) {
        qDebug() << "JSON Format Error";
        return false;
    }
}

QJsonObject ConfigUtils::getConfigRoot() {
    return doc_root->object();
}

QJsonValue ConfigUtils::getConfig(QString key) {
    return getConfigRoot().value(key);
}

ConfigFile::ConfigFile() {
    config_file = new QFile;
}

ConfigFile::~ConfigFile() {
    delete config_file;
}

ConfigFile::ConfigFile(const QString &file_path): ConfigFile() {
    readFile(file_path);
}

bool ConfigFile::readFile(const QString &file_path) {
    config_file->setFileName(file_path);
    bool status = config_file->open(QIODevice::ReadOnly|QIODevice::Text);
    if (!status) {
        qDebug() << "Config file open error";
        return false;
    }

    QTextStream ts(config_file);
    auto ret = parseJson(ts.readAll().toUtf8());

    return ret;
}