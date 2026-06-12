#include <iostream>
#include "RideSystem.h"
#include "CityGraph.h"

using namespace std;

int main() {
    CityGraph city(6);

    city.addRoad(0, 1, 4, 50);
    city.addRoad(0, 2, 2, 20);
    city.addRoad(1, 3, 5, 80);
    city.addRoad(2, 3, 8, 10);
    city.addRoad(2, 4, 10, 0);
    city.addRoad(3, 5, 6, 40);
    city.addRoad(4, 5, 3, 5);

    RideSystem system;

    system.addDriver(101, "Aman", 0, true);
    system.addDriver(102, "Ravi", 2, true);
    system.addDriver(103, "Neha", 4, true);
    system.addDriver(104, "Priya", 5, true);
    system.addDriver(105, "Suresh", 1, true);

    system.addUserLocation(201, 3);
    system.addUserLocation(202, 5);
    system.addUserLocation(203, 1);
    system.addUserLocation(204, 0);
    system.addUserLocation(205, 4);

    system.addArea("Andheri", 50);
    system.addArea("Bandra", 120);
    system.addArea("Vashi", 70);
    system.addArea("Thane", 90);
    system.addArea("Dadar", 110);

    int choice;

    do {
        cout << "\n========== RideNow System ==========\n";
        cout << "1. Show Drivers\n";
        cout << "2. Add Admin Change\n";
        cout << "3. Undo Admin Change\n";
        cout << "4. Add Ride Request\n";
        cout << "5. Location Lookup\n";
        cout << "6. Show Busy Areas\n";
        cout << "7. Process Ride Requests\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            system.showDrivers();
        }

        else if (choice == 2) {
            string change;
            cin.ignore();
            cout << "Enter admin change: ";
            getline(cin, change);
            system.addAdminChange(change);
        }

        else if (choice == 3) {
            system.undoAdminChange();
        }

        else if (choice == 4) {
            int requestId, userId, pickupNode, dropNode;

            cout << "Enter Request ID: ";
            cin >> requestId;

            cout << "Enter User ID: ";
            cin >> userId;

            cout << "Enter Pickup Node: ";
            cin >> pickupNode;

            cout << "Enter Drop Node: ";
            cin >> dropNode;

            system.addRideRequest(requestId, userId, pickupNode, dropNode);
        }

        else if (choice == 5) {
            int userId;
            cout << "Enter User ID: ";
            cin >> userId;
            system.showUserLocation(userId);
        }

        else if (choice == 6) {
            system.showBusyAreas();
        }

        else if (choice == 7) {
            system.processRides(city);
        }

        else if (choice == 8) {
            cout << "Exiting RideNow System.\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}