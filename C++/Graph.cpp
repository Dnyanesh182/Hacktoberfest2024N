#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>

class Graph {
private:
    // Adjacency list representation
    std::unordered_map<int, std::list<int>> adjList;

public:
    // Function to add an edge to the graph
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1); // Since the graph is undirected
    }

    // Function to display the graph
    void displayGraph() {
        std::cout << "Graph adjacency list:\n";
        for (const auto& vertex : adjList) {
            std::cout << vertex.first << ": ";
            for (int neighbor : vertex.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    // Breadth-First Search (BFS) traversal from a starting vertex
    void BFS(int start) {
        std::unordered_map<int, bool> visited;
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        std::cout << "BFS Traversal: ";
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            std::cout << v << " ";

            // Visit all adjacent vertices
            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    }

    // Depth-First Search (DFS) traversal from a starting vertex
    void DFS(int start) {
        std::unordered_map<int, bool> visited;
        std::stack<int> s;

        s.push(start);

        std::cout << "DFS Traversal: ";
        while (!s.empty()) {
            int v = s.top();
            s.pop();

            // If not visited, mark as visited and process
            if (!visited[v]) {
                std::cout << v << " ";
                visited[v] = true;
            }

            // Push all unvisited adjacent vertices to the stack
            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Graph g;

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);

    // Display the adjacency list
    g.displayGraph();

    // Perform BFS and DFS starting from vertex 0
    g.BFS(0);
    g.DFS(0);

    return 0;
}
