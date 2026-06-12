#ifndef CITYGRAPH_H
#define CITYGRAPH_H

#include <vector>
#include <string>
using namespace std;

struct Road {
    int to;
    int time;
    int toll;
};

struct RouteResult {
    int totalTime;
    int totalToll;
    string routeType;
};

class CityGraph {
    int vertices;
    vector<vector<Road>> adj;

public:
    CityGraph(int v);

    void addRoad(int u, int v, int time, int toll);

    RouteResult fastestRoute(int source, int destination);
    RouteResult tollSavingRoute(int source, int destination);
    RouteResult smartRoute(int source, int destination);
};

#endif