# RideNow: Smart Ride-Sharing Management System

## 2.1 Project Title

**RideNow: Smart Ride-Sharing Management System using Data Structures and Algorithms**

---

## 2.2 Problem Statement

Modern ride-sharing platforms such as Uber and Ola require efficient management of drivers, passengers, ride requests, route selection, and administrative operations. The system must process ride requests fairly, quickly locate drivers, optimize routes, maintain city traffic information, and support rollback of administrative changes.

The objective of this project is to simulate a ride-sharing platform using Data Structures and Algorithms (DSA) to achieve efficient data management and route optimization.

---

## 2.3 Objectives

* Manage driver information efficiently.
* Process ride requests in the order they are received.
* Maintain user location records for quick retrieval.
* Rank city areas based on ride demand.
* Support rollback of administrative changes.
* Find the nearest available driver.
* Optimize route selection using shortest-path algorithms.
* Demonstrate practical applications of DSA concepts.

---

## 2.4 System Overview / Architecture

### Components

1. Driver Management Module
2. Ride Request Management Module
3. Location Lookup Module
4. Busy Area Analysis Module
5. Route Optimization Module
6. Administrative Settings Module

<img width="358" height="397" alt="image" src="https://github.com/user-attachments/assets/70f10441-98db-4af5-a08e-b3014ff90da3" />


---

## 2.5 Data Structures and Algorithms Used

| Component                   | Data Structure / Algorithm |
| --------------------------- | -------------------------- |
| Driver Directory            | B-Tree                     |
| Administrative Rollback     | Stack                      |
| Ride Request Processing     | Queue                      |
| User Location Lookup        | Hash Map (unordered_map)   |
| Busy Area Ranking           | Sorting                    |
| City Road Network           | Graph                      |
| Fastest Route Selection     | Dijkstra Algorithm         |
| Toll-Saving Route Selection | Modified Dijkstra          |

### Why These Structures?

#### B-Tree

Used to efficiently store and retrieve driver records.

#### Stack

Used for undoing the most recent administrative changes.

#### Queue

Ensures ride requests are processed fairly using FIFO order.

#### Hash Map

Provides fast access to user location information.

#### Graph

Represents the city road network.

#### Dijkstra Algorithm

Finds the shortest and most efficient routes.

---

## 2.6 Implementation Approach

### Driver Management

Drivers are stored inside a B-Tree using Driver IDs as keys.

### Ride Request Processing

Each ride request is inserted into a Queue and processed in FIFO order.

### Location Lookup

User locations are stored using a Hash Map for O(1) average lookup time.

### Area Demand Ranking

Areas are sorted according to ride demand using sorting algorithms.

### Route Optimization

The city is represented as a weighted graph.

* Edge Weight 1 = Travel Time
* Edge Weight 2 = Toll Cost

Dijkstra's Algorithm is used to determine:

* Fastest Route
* Toll-Saving Route

### Driver Allocation

The nearest available driver is selected by comparing route travel times.

---

## 2.7 Time and Space Complexity Analysis

### B-Tree

| Operation | Complexity |
| --------- | ---------- |
| Search    | O(log n)   |
| Insert    | O(log n)   |

### Stack

| Operation | Complexity |
| --------- | ---------- |
| Push      | O(1)       |
| Pop       | O(1)       |

### Queue

| Operation | Complexity |
| --------- | ---------- |
| Enqueue   | O(1)       |
| Dequeue   | O(1)       |

### Hash Map

| Operation | Complexity   |
| --------- | ------------ |
| Search    | O(1) Average |

### Sorting

| Operation  | Complexity |
| ---------- | ---------- |
| Sort Areas | O(n log n) |

### Dijkstra Algorithm

| Operation    | Complexity       |
| ------------ | ---------------- |
| Route Search | O((V + E) log V) |

Where:

* V = Number of vertices
* E = Number of edges

---

## 2.8 Execution Steps

### Compilation

```bash
g++ main.cpp CityGraph.cpp RideSystem.cpp -o rideNow
```

### Run

```bash
./rideNow
```

### Menu Options

1. Show Drivers
2. Add Admin Change
3. Undo Admin Change
4. Add Ride Request
5. Location Lookup
6. Show Busy Areas
7. Process Ride Requests
8. Exit

---

## 2.9 Sample Inputs and Outputs

### Sample Input

```text
1
2
Bonus rule changed to 20%
3
4
1
201
3
5
7
8
```

### Sample Output

```text
Driver Directory using B-Tree:

ID: 101 | Name: Aman
ID: 102 | Name: Ravi
ID: 103 | Name: Neha

Undoing: Bonus rule changed to 20%
Rollback successful.

Ride request added successfully.

Processing Ride Request ID: 1

Assigned Driver: Ravi

Selected Route Type: Toll Saving Route

Total Time: 11 minutes

Total Toll: Rs. 15
```

---

## 2.10 Screenshots

Add screenshots of the following:

### Screenshot 1

Main Menu

### Screenshot 2

Driver Directory

### Screenshot 3

Adding Ride Request

### Screenshot 4

Processing Ride Request

### Screenshot 5

Busy Area Ranking

### Screenshot 6

Location Lookup

Store screenshots inside:

```text
screenshots/
```

---

## 2.11 Results and Observations

* Driver information was retrieved efficiently using B-Tree.
* Ride requests were processed fairly using Queue.
* User locations were accessed quickly using Hash Maps.
* Administrative changes could be rolled back using Stack.
* Busy areas were successfully ranked using Sorting.
* Dijkstra's Algorithm effectively selected optimal routes.
* The system successfully simulated core ride-sharing operations using DSA concepts.

---

## 2.12 Conclusion

The RideNow system successfully demonstrates the practical application of Data Structures and Algorithms in a ride-sharing environment. The project integrates B-Tree, Stack, Queue, Hash Map, Sorting, Graphs, and Dijkstra's Algorithm to efficiently manage drivers, passengers, ride requests, and route optimization. The implementation highlights how appropriate data structures improve performance, scalability, and overall system efficiency.

---

## Developed For

Data Structures and Algorithms (DSA) Mini Project

RideNow: Smart Ride-Sharing Management System
