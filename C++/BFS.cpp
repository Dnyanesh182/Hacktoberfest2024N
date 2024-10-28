#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

class Graph {
private:
    // Adjacency list to represent the graph
    std::unordered_map<int, std::list<int>> adjList;

public:
    // Function to add an edge between two vertices
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2); // Add v2 to v1's list
        adjList[v2].push_back(v1); // Since the graph is undirected, add v1 to v2's list
    }

    // Function to perform BFS traversal starting from a given source vertex
    void BFS(int start) {
        // Vector to keep track of visited nodes
        std::unordered_map<int, bool> visited;

        // Queue to assist in BFS
        std::queue<int> q;

        // Mark the starting node as visited and enqueue it
        visited[start] = true;
        q.push(start);

        std::cout << "BFS traversal starting from vertex " << start << ": ";

        // Continue the BFS until the queue is empty
        while (!q.empty()) {
            // Dequeue a vertex from the queue
            int vertex = q.front();
            q.pop();

            std::cout << vertex << " ";

            // Iterate through all adjacent vertices of the dequeued vertex
            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {  // If a neighbor hasn't been visited
                    visited[neighbor] = true;  // Mark it as visited
                    q.push(neighbor);          // Enqueue it
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Graph g;

    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Perform BFS starting from vertex 0
    g.BFS(0);

    return 0;
}
