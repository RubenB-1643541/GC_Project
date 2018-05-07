#include "datafilewriter.h"

DataFileWriter::DataFileWriter()
{
    WriteToFile();
}

bool DataFileWriter::WriteToFile() {
    QFile saveFile("WorldData/WorldData.json");

    if(!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }
    QJsonObject object;
    QJsonObject world_object;
    WriteOverWorld(world_object);
    object["over_world"] = world_object;
    QJsonArray entities;
    WriteEntities(entities);
    object["entities"] = entities;
    QJsonDocument saveDoc(object);
    saveFile.write(saveDoc.toJson());
}

void DataFileWriter::WriteOverWorld(QJsonObject &obj) {
    obj["data"] = "Models/Bobomb/bobomb battlefeild.obj";
    obj["size"] = 1;
    QJsonObject position;
    SetPosition(position, __3DWorld__::Point3D(0,0,0));
    obj["position"] = position;
    QJsonObject rotation;
    SetRotation(rotation,0, __3DWorld__::Point3D(0, 0, 0));
    obj["rotation"] = rotation;
}

void DataFileWriter::WriteEntities(QJsonArray &array) {
    QJsonObject spider;
    WriteSpider(spider);
    array.append(spider);
}

void DataFileWriter::WriteSpider(QJsonObject &obj) {
    obj["data"] = "Models/Spider/spider.obj";
    obj["size"] = 0.05;
    QJsonObject position;
    SetPosition(position, __3DWorld__::Point3D(21, 25.5, 7));
    obj["position"] = position;
    QJsonObject rotation;
    SetRotation(rotation, 180, __3DWorld__::Point3D(0, 1, 0));
    obj["rotation"] = rotation;
    obj["behavior"] = "Spider";
}

void DataFileWriter::SetPosition(QJsonObject &obj, __3DWorld__::Point3D pos) {
    obj["x"] = pos.x();
    obj["y"] = pos.y();
    obj["z"] = pos.z();
}

void DataFileWriter::SetRotation(QJsonObject &obj, float angle, __3DWorld__::Point3D rot) {
    obj["x"] = rot.x();
    obj["y"] = rot.y();
    obj["z"] = rot.z();
    obj["angle"] = angle;
}

