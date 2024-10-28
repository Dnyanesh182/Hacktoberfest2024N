#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

class Graph {
private:
    // Adjacency list to represent the graph
    std::unordered_map<int, std::list<int>> adjList;

    // Helper function for DFS that uses recursion
    void DFSUtil(int vertex, std::unordered_map<int, bool> &visited) {
        // Mark the current node as visited and print it
        visited[vertex] = true;
        std::cout << vertex << " ";

        // Recursively visit all adjacent vertices that haven't been visited
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    // Function to add an edge between two vertices
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2); // Add v2 to v1's list
        adjList[v2].push_back(v1); // Since the graph is undirected, add v1 to v2's list
    }

    // Function to perform DFS traversal starting from a given source vertex
    void DFS(int start) {
        // Keep track of visited nodes
        std::unordered_map<int, bool> visited;

        std::cout << "DFS traversal starting from vertex " << start << ": ";
        // Start the DFS traversal from the given starting vertex
        DFSUtil(start, visited);
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

    // Perform DFS starting from vertex 0
    g.DFS(0);

    return 0;
}
