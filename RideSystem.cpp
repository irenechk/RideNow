#include "RideSystem.h"
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void RideSystem::addDriver(int id, string name, int locationNode, bool available) {
    Driver d = {id, name, locationNode, available};
    driverDirectory.insertDriver(d);
}

void RideSystem::showDrivers() {
    driverDirectory.displayDrivers();
}

void RideSystem::addUserLocation(int userId, int locationNode) {
    userLocation[userId] = locationNode;
}

void RideSystem::showUserLocation(int userId) {
    if (userLocation.find(userId) != userLocation.end()) {
        cout << "User " << userId << " is at location node "
             << userLocation[userId] << endl;
    } else {
        cout << "User not found.\n";
    }
}

void RideSystem::addAdminChange(string change) {
    adminChanges.push(change);
    cout << "Admin change added.\n";
}

void RideSystem::undoAdminChange() {
    if (!adminChanges.empty()) {
        cout << "Undoing: " << adminChanges.top() << endl;
        adminChanges.pop();
        cout << "Rollback successful.\n";
    } else {
        cout << "No admin change to undo.\n";
    }
}

void RideSystem::addRideRequest(int requestId, int userId, int pickupNode, int dropNode) {
    rideQueue.push({requestId, userId, pickupNode, dropNode});
    cout << "Ride request added successfully.\n";
}

void RideSystem::addArea(string name, int demand) {
    areas.push_back({name, demand});
}

void RideSystem::showBusyAreas() {
    sort(areas.begin(), areas.end(), [](Area a, Area b) {
        return a.demand > b.demand;
    });

    cout << "\nBusy Area Ranking:\n";

    for (auto area : areas) {
        cout << area.name << " - Demand: " << area.demand << endl;
    }
}

int RideSystem::findNearestDriver(CityGraph &city, int pickupNode) {
    vector<Driver> drivers = driverDirectory.getAllDrivers();

    int nearestDriverId = -1;
    int minimumTime = INT_MAX;

    for (auto driver : drivers) {
        if (driver.available) {
            RouteResult route = city.fastestRoute(driver.locationNode, pickupNode);

            if (route.totalTime < minimumTime) {
                minimumTime = route.totalTime;
                nearestDriverId = driver.id;
            }
        }
    }

    return nearestDriverId;
}

void RideSystem::processRides(CityGraph &city) {
    if (rideQueue.empty()) {
        cout << "No ride requests available.\n";
        return;
    }

    while (!rideQueue.empty()) {
        RideRequest request = rideQueue.front();
        rideQueue.pop();

        cout << "\nProcessing Ride Request ID: " << request.requestId << endl;

        int driverId = findNearestDriver(city, request.pickupNode);

        if (driverId == -1) {
            cout << "No available driver found.\n";
            continue;
        }

        Driver* driver = driverDirectory.searchDriver(driverId);

        cout << "Assigned Driver: " << driver->name << endl;

        RouteResult route = city.smartRoute(request.pickupNode, request.dropNode);

        cout << "Selected Route Type: " << route.routeType << endl;
        cout << "Total Time: " << route.totalTime << " minutes\n";
        cout << "Total Toll: Rs. " << route.totalToll << endl;

        driver->available = false;
    }
}