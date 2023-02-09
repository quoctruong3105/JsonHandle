#include "converter.h"

converter::converter(QObject *parent) : QObject(parent)
{

}

void converter::writeJson(test *obj, QString path)
{
    QVariantMap map;
    QVariantMap info;
    QVariantList items;

    foreach(QVariant variant, obj->list()) {
        items.append(variant);
    }

    foreach(QString key, obj->map().keys()) {
        map.insert(key, QVariant(obj->map().value(key)));
    }

    info["info"] = map;

    QJsonDocument document = QJsonDocument::fromVariant(info);

    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) {
        qCritical() << "Could not write file!";
        qCritical() << file.errorString();
        return;
    }

    file.write(document.toJson());
    file.close();
}

test *converter::readJson(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Could not read file!";
        qCritical() << file.errorString();
        return nullptr;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(data);
    test *t = new test();


    QVariantMap vmap = qvariant_cast<QVariantMap>(document["info"]);
    QMap<QString, QList<QVariant>> map;
    foreach(QString key, vmap.keys()) {
        QVariantList items = qvariant_cast<QVariantList>(document[key]);
        items = vmap.value(key).toList();
        QVariantList list;
        foreach(QVariant variant, items) {
            list.append(variant);
        }
        map.insert(key, list);
    }

    t->setMap(map);

    return  t;

}

QVariantList converter::getData(int index)
{
    QString path = "test.txt";
    test *t = new test();
    t = readJson(path);
    for(int i = 0; i < t->map().size(); i++) {
        if(i !=  index) {
            continue;
        }
        else {
            QMap<QString, QVariantList> newMap;
            newMap = t->map();
            QVariantList newList = t->map().value("user " + QString::number(i));
            QString name = newList[0].toString();
            int age = newList[1].toInt();
            QString phoneNumber = newList[2].toString();
//            qInfo() << name;
//            qInfo() << age;
//            qInfo() << phoneNumber;
            //qInfo() << "success";
            return newList;
            break;
        }
    }
}
















