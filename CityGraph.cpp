#include "CityGraph.h"
#include <queue>
#include <climits>
using namespace std;

CityGraph::CityGraph(int v) {
    vertices = v;
    adj.resize(v);
}

void CityGraph::addRoad(int u, int v, int time, int toll) {
    adj[u].push_back({v, time, toll});
    adj[v].push_back({u, time, toll});
}

RouteResult CityGraph::fastestRoute(int source, int destination) {
    vector<int> time(vertices, INT_MAX);
    vector<int> toll(vertices, INT_MAX);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    time[source] = 0;
    toll[source] = 0;

    pq.push({0, source});

    while (!pq.empty()) {
        int currentTime = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto road : adj[node]) {
            int newTime = currentTime + road.time;
            int newToll = toll[node] + road.toll;

            if (newTime < time[road.to]) {
                time[road.to] = newTime;
                toll[road.to] = newToll;
                pq.push({newTime, road.to});
            }
        }
    }

    return {time[destination], toll[destination], "Fastest Route"};
}

RouteResult CityGraph::tollSavingRoute(int source, int destination) {
    vector<int> toll(vertices, INT_MAX);
    vector<int> time(vertices, INT_MAX);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    toll[source] = 0;
    time[source] = 0;

    pq.push({0, source});

    while (!pq.empty()) {
        int currentToll = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto road : adj[node]) {
            int newToll = currentToll + road.toll;
            int newTime = time[node] + road.time;

            if (newToll < toll[road.to]) {
                toll[road.to] = newToll;
                time[road.to] = newTime;
                pq.push({newToll, road.to});
            }
        }
    }

    return {time[destination], toll[destination], "Toll Saving Route"};
}

RouteResult CityGraph::smartRoute(int source, int destination) {
    RouteResult fastest = fastestRoute(source, destination);
    RouteResult tollSaver = tollSavingRoute(source, destination);

    int allowedExtraTime = 5;

    if (tollSaver.totalToll < fastest.totalToll &&
        tollSaver.totalTime <= fastest.totalTime + allowedExtraTime) {
        return tollSaver;
    }

    return fastest;
}