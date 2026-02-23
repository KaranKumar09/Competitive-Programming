#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// Graph class definition
class Graph {
private:
    unordered_map<int, vector<int>> adjList;

public:
    void addEdge(int u, int v, bool isDirected = false) {
        adjList[u].push_back(v);
        if (!isDirected) {
            adjList[v].push_back(u);
        }
    }

    void display() const {
        for (const auto& pair : adjList) {
            cout << pair.first << " -> ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(int node, set<int>& visited) {
        cout << node << " ";
        visited.insert(node);
        
        for (int neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs(int startNode) {
        set<int> visited;
        cout << "DFS Traversal: ";
        dfsHelper(startNode, visited);
        cout << endl;
    }
};

int main() {
    Graph g;
    int n, u, v, startNode;
    bool isDirected;

    // Input the number of edges
    cout << "Enter the number of edges: ";
    cin >> n;

    // Input the type of graph
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> isDirected;

    // Input the edges using a loop
    cout << "Enter the edges (u v) one by one:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        g.addEdge(u, v, isDirected);
    }

    // Display the adjacency list of the graph
    cout << "Graph adjacency list:" << endl;
    g.display();

    // Input the starting node for DFS
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    // Perform DFS traversal
    g.dfs(startNode);

    return 0;
}
