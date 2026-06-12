#ifndef RIDESYSTEM_H
#define RIDESYSTEM_H

#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <string>

#include "Driver.h"
#include "RideRequest.h"
#include "Area.h"
#include "BTree.h"
#include "CityGraph.h"

using namespace std;

class RideSystem {
    BTree driverDirectory;
    unordered_map<int, int> userLocation;
    stack<string> adminChanges;
    queue<RideRequest> rideQueue;
    vector<Area> areas;

public:
    void addDriver(int id, string name, int locationNode, bool available);
    void showDrivers();

    void addUserLocation(int userId, int locationNode);
    void showUserLocation(int userId);

    void addAdminChange(string change);
    void undoAdminChange();

    void addRideRequest(int requestId, int userId, int pickupNode, int dropNode);

    void addArea(string name, int demand);
    void showBusyAreas();

    int findNearestDriver(CityGraph &city, int pickupNode);
    void processRides(CityGraph &city);
};

#endif