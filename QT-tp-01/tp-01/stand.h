#ifndef STAND_H
#define STAND_H

#include <QMap>
#include <Qlist>
#include <QVector>

#include "vehicle.h"

class QString;

// Stand CLASS
class Stand {
private:
    QString cityName; // City where the stand is located
    int number{};  // An integer between 1 and 99
    QString code; // Unique code based on city and number

public:
    // Constructor
    Stand();

    // Constructor with arguments
    Stand(const QString& cityName, int number);

    QString getCityName() const;
    int getNumber() const;

    QString toString() const; // Return the code concatenated from the city name and the stand number
};

/* ----------------------- GestStand CLASS -------------------------*/

// GestStand ABSTRACT CLASS
class GestStand {
public:
    // Add a vehicle to a stand
    virtual int addVehicleToStand(Vehicle* vehicle, Stand* stand) = 0;

    // Display all the stands and its associated vehicles
    virtual void displayMapStandsVehicles() const = 0;

    // Add a stand to the map
    virtual int addStand(const QString& cityName, int number) = 0;

    // Find a stand by code
    virtual Stand* findStandByCode(const QString& standCode) const = 0;

    // Remove a stand by code
    virtual int removeStandByCode(const QString& standCode) = 0;

    // Save stands data to a text file
    virtual int saveStandsDataTxt() = 0;

    // Get the list of vehicles associated with a stand
    virtual VehicleList* getVehicleListByStand(Stand* stand) const = 0;

    // Display all available stands
    virtual void displayStands() const = 0;

    // Move a vehicle from one stand to another
    // virtual void moveVehicle(Vehicle* vehicle, const QString& destinationStandCode) = 0;

    //virtual Stand *findStandByVehicleID(int vehicleID) const = 0;

   // virtual Vehicle* findVehicleByID(int vehicleID) const = 0;

   // virtual int removeVehicleByID(int vehicleID) =0;

   // virtual const QMap<Stand *, VehicleList *> &getStandVehicleMap() const = 0;

    // Load stands and associated vehicles from a text file
    virtual int loadStandsDataTxt() = 0;

    virtual ~GestStand() = default; // Destructor
};

/* ----------------------- VehicleStand CLASS -------------------------*/

// VehicleStand CLASS
class VehicleStand : public GestStand {
private:
    // QMap of the Vehicles and Stands
    QMap<Stand*, VehicleList*> standVehicleMap;

public:
    // Constructor
    VehicleStand();

    int addVehicleToStand(Vehicle* vehicle, Stand* stand) override;
    //void moveVehicle(Vehicle* vehicle, const QString& destinationStandCode) override;
    void displayStands() const override;
    void displayMapStandsVehicles() const override;
    int addStand(const QString& cityName, int number) override;
    Stand* findStandByCode(const QString& standCode) const override;
    int removeStandByCode(const QString& standCode) override;
    int saveStandsDataTxt() override;
    VehicleList* getVehicleListByStand(Stand* stand) const override;
    //Stand *findStandByVehicleID(int vehicleID) const override;
    //Vehicle* findVehicleByID(int vehicleID) const override;
    //int removeVehicleByID(int vehicleID) override;
    //const QMap<Stand*, VehicleList*>& getStandVehicleMap() const override;
    int loadStandsDataTxt() override;
};

#endif //STAND_H
