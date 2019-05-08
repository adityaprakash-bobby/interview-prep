#include <iostream>
#include <list>

/* Implementation of Breadth First Search algorithm */

// Represent graph using adjacency list
class Graph {

    // Number of vertices or nodes
    int V;

    // Adjacency list for the nodes
    std::list<int> *adjacent;

    // A function to make recursion possible inside the 'dfs' 
    // function
    void dfs_recursion(int v, bool visited[]);

    public:
    // Constructor to initialize the graph
    Graph(int V);

    // Function to add edge to the graph
    void add_edge(int v, int w);

    // Funtion to find the BFS from a node
    void dfs(int v);
};

Graph::Graph(int V) {
    
    this->V = V;
    adjacent = new std::list<int>[V];

}

void Graph::add_edge(int v, int w) {

    adjacent[v].push_back(w);

}

void Graph::dfs_recursion(int v, bool visited[]) {

    // Mark the starting node as 'visited' and print the node
    visited[v] = true;
    std::cout << v << " ";

    for (auto i = adjacent[v].begin(); i != adjacent[v].end(); i++) {

        if (!visited[*i]) {

            this->dfs_recursion(*i, visited);

        }

    }
    
}

void Graph::dfs(int v) {

    // Mark all nodes as 'not visited'
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    dfs_recursion(v, visited);

}


int main(int argc, char const *argv[])
{
    // Initialize a Graph object and add the edges to the graph
    Graph G(4);
    G.add_edge(0, 1);
    G.add_edge(0, 2);
    G.add_edge(1, 2);
    G.add_edge(2, 0);
    G.add_edge(2, 3);
    G.add_edge(3, 3);

    // Get the dfs traversal of the graph
    G.dfs(2);

    // Gracefully exit
    return 0;
}