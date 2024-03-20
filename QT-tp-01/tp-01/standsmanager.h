#ifndef STANDSMANAGER_H
#define STANDSMANAGER_H

#include <QObject>
#include <QMap>

#include "stand.h"

class StandsManager : public QObject
{
    Q_OBJECT

public:
    explicit StandsManager(QObject *parent = nullptr);
    ~StandsManager();

public slots:
    int createStand(const QString &cityName, int standNumber);

signals:


private:
    QMap<Stand*, VehicleList*> stands;

};

#endif // STANDSMANAGER_H
