#ifndef DATAFILEWRITER_H
#define DATAFILEWRITER_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <Point3D.h>
#include "Entities/thwomp.h"

class DataFileWriter
{
public:
    DataFileWriter();

private:
    bool WriteToFile();
    void WriteOverWorld(QJsonObject &obj);
    void WriteEntities(QJsonArray &array);
    void WriteSpider(QJsonObject &obj);
    void WriteThwomp(QJsonObject &obj);
    void SetPosition(QJsonObject &obj, __3DWorld__::Point3D pos);
    void SetRotation(QJsonObject &obj, float angle, __3DWorld__::Point3D rot);
};

#endif // DATAFILEWRITER_H
