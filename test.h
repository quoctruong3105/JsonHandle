#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QList>
#include <QDataStream>
#include <QVariantList>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    void fill();

    QList<QVariant> list();
    QMap<QString, QList<QVariant>> map();
    void setList(QVariantList list);
    void setMap(QMap<QString, QList<QVariant>> map);
    void setName(QString name);
    void setPhone(QString phone);
    void setAge(int age);


    friend QDataStream& operator <<(QDataStream &stream, const test &t) {
        qInfo() << "Operload <<";
        stream << t.mList;
        stream << t.mName;
        stream << t.mPhoneNum;
        stream << t.mAge;
        stream << t.mMap;
        return stream;
    }

    friend QDataStream& operator >>(QDataStream &stream, test &t) {
        qInfo() << "Operload >>";
        stream >> t.mList;
        stream >> t.mName;
        stream >> t.mPhoneNum;
        stream >> t.mAge;
        stream >> t.mMap;
        return stream;
    }

signals:

public slots:
    QString name();
    int age();
    QString phoneNum();

private:
    QString mName;
    QString mPhoneNum;
    int mAge;
    QList<QVariant> mList;
    QMap<QString, QList<QVariant>> mMap;
};

#endif // TEST_H
