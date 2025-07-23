#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>
#include <stack>
#include <list>
#include <stdexcept>

using namespace std;

// =================== CO1 & CO2: Basic Class Design ===================

class Router {
public:
    int id;
    Router(int id) : id(id) {}
};

class Edge {
public:
    int src, dest, cost;
    Edge(int s, int d, int c) : src(s), dest(d), cost(c) {}
};

// =================== CO3: Templates, Constructor, Destructor ===================

template <typename T>
class Graph {
private:
    map<int, T*> nodes;
    map<int, list<Edge>> adjList;

public:
    Graph() {}
    ~Graph() {
        for (auto& n : nodes) delete n.second;
    }

    void addNode(int id) {
        nodes[id] = new T(id);
        adjList[id];  // Ensure all nodes are added to adjList
    }

    void addEdge(int src, int dest, int cost) {
        adjList[src].push_back(Edge(src, dest, cost));
    }

    map<int, list<Edge>> getAdjList() const {
        return adjList;
    }

    map<int, T*> getNodes() const {
        return nodes;
    }

    // Operator Overloading (CO3)
    T* operator[](int id) {
        if (nodes.find(id) == nodes.end()) throw out_of_range("Router not found!");
        return nodes[id];
    }
};

// =================== CO4: Inheritance & Polymorphism ===================

class RoutingAlgorithm {
public:
    virtual void compute(int source) = 0;
    virtual ~RoutingAlgorithm() {}
};

class Dijkstra : public RoutingAlgorithm {
private:
    Graph<Router>& graph;

public:
    Dijkstra(Graph<Router>& g) : graph(g) {}

    void compute(int source) override {
        map<int, int> dist;
        map<int, int> prev;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto& node : graph.getNodes()) {
            dist[node.first] = INT_MAX;
            prev[node.first] = -1;
        }
        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& edge : graph.getAdjList().at(u)) {
                int v = edge.dest;
                int weight = edge.cost;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra's Algorithm (Source: " << source << ")\n";
        for (auto& [v, d] : dist) {
            cout << "To " << v << " - Cost: " << d << " | Path: ";
            stack<int> path;
            for (int at = v; at != -1; at = prev[at]) path.push(at);
            while (!path.empty()) {
                cout << path.top() << " ";
                path.pop();
            }
            cout << endl;
        }
    }
};

// =================== CO5: Bellman-Ford & Exception Handling ===================

class BellmanFord : public RoutingAlgorithm {
private:
    Graph<Router>& graph;

public:
    BellmanFord(Graph<Router>& g) : graph(g) {}

    void compute(int source) override {
        map<int, int> dist, prev;
        for (auto& node : graph.getNodes()) {
            dist[node.first] = INT_MAX;
            prev[node.first] = -1;
        }
        dist[source] = 0;

        int V = graph.getNodes().size();
        for (int i = 1; i < V; ++i) {
            for (auto& node : graph.getNodes()) {
                int u = node.first;
                for (const auto& edge : graph.getAdjList().at(u)) {
                    int v = edge.dest, w = edge.cost;
                    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        prev[v] = u;
                    }
                }
            }
        }

        // Exception Handling (CO5)
        for (auto& node : graph.getNodes()) {
            int u = node.first;
            for (const auto& edge : graph.getAdjList().at(u)) {
                int v = edge.dest, w = edge.cost;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    throw runtime_error("Graph contains a negative weight cycle");
                }
            }
        }

        cout << "Bellman-Ford Algorithm (Source: " << source << ")\n";
        for (auto& [v, d] : dist) {
            cout << "To " << v << " - Cost: " << d << " | Path: ";
            stack<int> path;
            for (int at = v; at != -1; at = prev[at]) path.push(at);
            while (!path.empty()) {
                cout << path.top() << " ";
                path.pop();
            }
            cout << endl;
        }
    }
};

// =================== MAIN FUNCTION ===================

int main() {
    Graph<Router> g;

    // Add routers
    for (int i = 1; i <= 4; i++) g.addNode(i);

    // Add edges
    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 1);
    g.addEdge(3, 2, 2);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 5);

    int src;
    cout << "Enter source router: ";
    cin >> src;

    cout << "Choose algorithm: 1. Dijkstra  2. Bellman-Ford\n";
    int choice;
    cin >> choice;

    RoutingAlgorithm* algo = nullptr;
    try {
        if (choice == 1) algo = new Dijkstra(g);
        else if (choice == 2) algo = new BellmanFord(g);
        else throw invalid_argument("Invalid algorithm choice");

        algo->compute(src);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    delete algo;
    return 0;
}
