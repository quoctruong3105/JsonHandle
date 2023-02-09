#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

void test::fill()
{
    for(int i = 0; i < 40; i++) {
        QVariantList list;
        QString name = "Truong" + QString::number(i);
        QString phoneNumber = "0365352917";
        int age = 22;

        list.append(name);
        list.append(age);
        list.append(phoneNumber);

        mList.append(list);
        mMap.insert("user " + QString::number(i), list);
    }
}

QString test::name()
{
    return mName;
}

int test::age()
{
    return mAge;
}

QString test::phoneNum()
{
    return mPhoneNum;
}

QList<QVariant> test::list()
{
    return mList;
}

QMap<QString, QList<QVariant> > test::map()
{
    return mMap;
}

void test::setList(QVariantList list)
{
    mList = list;
}

void test::setMap(QMap<QString, QList<QVariant>> map)
{
    mMap = map;
}

void test::setName(QString name)
{
    mName = name;
}

void test::setPhone(QString phone)
{
    mPhoneNum = phone;
}

void test::setAge(int age)
{
    mAge = age;
}

