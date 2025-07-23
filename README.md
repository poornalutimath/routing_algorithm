# 🔀 Router Pathfinding using Dijkstra and Bellman-Ford Algorithms

## 📌 Project Description

This C++ program simulates a network of routers and computes the shortest path between them using:

- **Dijkstra's Algorithm** – for graphs with non-negative weights.
- **Bellman-Ford Algorithm** – handles negative weights and detects negative weight cycles.

It uses object-oriented programming (OOP) and demonstrates templates, inheritance, polymorphism, operator overloading, and exception handling.

---

## 🧠 Concepts Implemented

- ✅ Object-Oriented Programming (OOP)
- ✅ Templates and Operator Overloading
- ✅ Inheritance and Polymorphism
- ✅ Exception Handling
- ✅ Graph Algorithms (Dijkstra and Bellman-Ford)

---

## 🛠 Technologies Used

- C++ (Standard Template Library)
- GCC compiler / VS Code / any C++ IDE

---

## 📂 File Structure

router-pathfinding/
├── routing_algorithms.cpp # Main source code
└── README.md # Project documentation


---

## 🚀 How to Compile and Run

### Step 1: Save the Code
Save the code as `routing.cpp`.

### Step 2: Compile
```bash
g++ routing.cpp -o routing

### Step 3: Run
'''bash
./routing      # For Linux/macOS
routing.exe    # For Windows

Sample Input/Output
Enter source router: 1
Choose algorithm: 1. Dijkstra  2. Bellman-Ford
1

Dijkstra's Algorithm (Source: 1)
To 1 - Cost: 0 | Path: 1 
To 2 - Cost: 3 | Path: 1 3 2 
To 3 - Cost: 1 | Path: 1 3 
To 4 - Cost: 4 | Path: 1 3 2 4

Code Components

| Component          | Description                                                       |
| ------------------ | ----------------------------------------------------------------- |
| `Router`           | Represents each router with an ID.                                |
| `Edge`             | Represents a connection with cost.                                |
| `Graph<T>`         | A template graph class for managing nodes and edges.              |
| `RoutingAlgorithm` | Abstract class (base) for pathfinding.                            |
| `Dijkstra`         | Inherits from `RoutingAlgorithm` and implements Dijkstra’s logic. |
| `BellmanFord`      | Inherits from `RoutingAlgorithm` and implements Bellman-Ford.     |
| `main()`           | Handles user interaction and runs the chosen algorithm.           |

Learning Outcomes:

Apply OOP principles in real-world simulations.
Learn and compare graph traversal algorithms.
Use C++ STL structures like map, list, stack, priority_queue.
Implement exception handling for robustness.

Author
Poorna N. Lutimath
Bachelor of Engineering – Electronics & Communication
Nitte Meenakshi Institute of Technology

 License
This project is for academic and educational use only.

---

Let me know if you want a `.pdf`, `.pptx`, or project report based on this!

