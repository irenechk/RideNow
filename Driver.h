#ifndef DRIVER_H
#define DRIVER_H

#include <string>
using namespace std;

struct Driver {
    int id;
    string name;
    int locationNode;
    bool available;
};

#endif