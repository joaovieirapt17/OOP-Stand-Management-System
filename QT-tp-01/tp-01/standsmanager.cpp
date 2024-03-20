#include "standsmanager.h"
#include <QDebug>

StandsManager::StandsManager(QObject *parent) : QObject(parent) {}

StandsManager::~StandsManager() {}

int StandsManager::createStand(const QString& cityName, int standNumber) {

    GestStand* gestStand = new VehicleStand();

    int result = gestStand->addStand(cityName, standNumber);
    qDebug() << "addStand result:" << result;

    // Save stands data to a text file
    result = gestStand->saveStandsDataTxt();
    if (result != 0) {
        qDebug() << "Error saving stands data to file. Code: " << result;
    } else {
        qDebug() << "Stands data saved successfully!";
    }

    return 0;
}
