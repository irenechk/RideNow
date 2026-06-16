# RideNow: Smart Ride-Sharing Management System

## 1 Project Title

**RideNow: Smart Ride-Sharing Management System using Data Structures and Algorithms**

---

## 2 Problem Statement

Modern ride-sharing platforms such as Uber and Ola require efficient management of drivers, passengers, ride requests, route selection, and administrative operations. The system must process ride requests fairly, quickly locate drivers, optimize routes, maintain city traffic information, and support rollback of administrative changes.

The objective of this project is to simulate a ride-sharing platform using Data Structures and Algorithms (DSA) to achieve efficient data management and route optimization.

## 2.1 Core Challenges
| **Challenge**                             | **Impact if Unresolved**                                                             |
| ----------------------------------------- | ------------------------------------------------------------------------------------ |
| Inefficient driver information management | Drivers cannot be located quickly, causing delays in ride assignment                 |
| Unfair ride request processing            | Some users may experience longer wait times while newer requests get processed first |
| Slow passenger location lookup            | Increased response time for driver allocation and ride matching                      |
| Poor driver allocation strategy           | Passengers face longer waiting times and drivers may be underutilized                |
| No route optimization mechanism           | Higher travel time, increased fuel consumption, and reduced customer satisfaction    |
| No toll-cost consideration in routing     | Passengers may incur unnecessary travel expenses                                     |
| Lack of administrative rollback support   | Incorrect system settings cannot be reverted easily, affecting operations            |
| No demand-based area analysis             | Drivers cannot identify high-demand zones, reducing service efficiency               |
| Manual management of large driver records | System performance decreases as the number of drivers grows                          |

---

## 3 Objectives

* Manage driver information efficiently.
* Process ride requests in the order they are received.
* Maintain user location records for quick retrieval.
* Rank city areas based on ride demand.
* Support rollback of administrative changes.
* Find the nearest available driver.
* Optimize route selection using shortest-path algorithms.
* Demonstrate practical applications of DSA concepts.

---

## 4 System Overview / Architecture

### Components

| **Module**         | **Class**            | **Responsibility**                                                                                                                       |
| ------------------ | -------------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| **BTree.h**        | `BTree`, `BTreeNode` | Store, search, insert, and manage driver records efficiently using a B-Tree.                                                             |
| **RideSystem.cpp** | `RideSystem`         | Manage drivers, user locations, ride requests, busy areas, and ride processing operations.                                               |
| **CityGraph.cpp**  | `CityGraph`          | Represent the city road network, manage routes, and perform fastest-route and toll-saving route calculations using Dijkstra's Algorithm. |
| **Driver.h**       | `Driver`             | Store driver information including ID, name, location, and availability status.                                                          |
| **RideRequest.h**  | `RideRequest`        | Store ride request details such as request ID, user ID, pickup node, and destination node.                                               |
| **Area.h**         | `Area`               | Store area demand information used for busy-area ranking and sorting.                                                                    |
| **RideSystem.cpp** | `RideSystem`         | Manage Queue-based ride requests, Stack-based admin rollback, Hash Map location lookup, and demand analysis.                             |
| **main.cpp**       | —                    | Main entry point; displays menu, handles user interaction, initializes sample data, and invokes system operations.                       |


<img width="358" height="397" alt="image" src="https://github.com/user-attachments/assets/70f10441-98db-4af5-a08e-b3014ff90da3" />


---

## 5 Data Structures and Algorithms Used

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

## 6 Implementation Approach

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

## 7 Time and Space Complexity Analysis

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

## 8 Execution Steps

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

## 10 Screenshots


Main Menu

<img width="305" height="154" alt="image" src="https://github.com/user-attachments/assets/9ccabf2c-9cca-4359-90bf-b87ad6780412" />



Driver Directory

<img width="481" height="254" alt="Drivers Directory " src="https://github.com/user-attachments/assets/544b2b92-72d3-434d-8cbf-885ce6e39de4" />



Adding Ride Request

<img width="387" height="463" alt="add ride request line " src="https://github.com/user-attachments/assets/6fcd093c-aff1-470a-b2f3-18a13890088c" />



Processing Ride Request

<img width="322" height="317" alt="Process Ride Requests" src="https://github.com/user-attachments/assets/079cd870-5bad-4b58-a07b-5a681fbb5471" />



Busy Area Ranking

<img width="291" height="255" alt="busy areas " src="https://github.com/user-attachments/assets/6f5c5bc3-6689-472d-b5c7-3900210424a0" />



Location Lookup

<img width="320" height="362" alt="Location lookup " src="https://github.com/user-attachments/assets/08edec6d-6846-468a-a2e5-e409ea8cc41b" />



---

## 11 Results and Observations

* Driver information was retrieved efficiently using B-Tree.
* Ride requests were processed fairly using Queue.
* User locations were accessed quickly using Hash Maps.
* Administrative changes could be rolled back using Stack.
* Busy areas were successfully ranked using Sorting.
* Dijkstra's Algorithm effectively selected optimal routes.
* The system successfully simulated core ride-sharing operations using DSA concepts.

---

## 12 Conclusion

The RideNow system successfully demonstrates the practical application of Data Structures and Algorithms in a ride-sharing environment. The project integrates B-Tree, Stack, Queue, Hash Map, Sorting, Graphs, and Dijkstra's Algorithm to efficiently manage drivers, passengers, ride requests, and route optimization. The implementation highlights how appropriate data structures improve performance, scalability, and overall system efficiency.

---

## Developed For

Data Structures and Algorithms (DSA) Finals Project

RideNow: Smart Ride-Sharing Management System
