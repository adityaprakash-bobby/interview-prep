#include <iostream>
#include <list>

/* Implementation of Breadth First Search algorithm */

// Represent graph using adjacency list
class Graph {

    // Number of vertices or nodes
    int V;

    // Adjacency list for the nodes
    std::list<int> *adjacent;
    
    public:
    // Constructor to initialize the graph
    Graph(int V);

    // Function to add edge to the graph
    void add_edge(int v, int w);

    // Funtion to find the BFS from a node
    void bfs(int v);
};

Graph::Graph(int V) {
    
    this->V = V;
    adjacent = new std::list<int>[V];

}

void Graph::add_edge(int v, int w) {

    adjacent[v].push_back(w);

}

void Graph::bfs(int v) {

    // Mark all nodes as 'not visited'
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Init a queue for keeping track of 'to-be-explored' nodes
    std::list<int> queue;

    // Start the search from node 'u' and mark 'v' as visited
    int u = v;
    visited[v] = true;

    // Repeat the looping until the 'queue' is empty 
    while(true) {

        // Print the visited nodes
        std::cout << u << " ";

        // For all the adjacent vertices of node 'u' do the following
        for (std::list<int>::iterator i = adjacent[u].begin(); \
                                  i != adjacent[u].end(); i++) {
            
            // If the adjacent nodes are not visited, mark them as visited
            // and push them to to-be-eplored 'queue'
            if (!visited[*i]) {

                visited[*i] = true;
                queue.push_back(*i);

            }

        }

        // If the queue is empty (i.e, all the nodes are explored) stop the
        // search, else continue the search
        if (queue.empty()) {

            return;

        }

        else {
            
            u = queue.front();
            queue.pop_front();

        }
        
    }

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

    // Get the bfs traversal of the graph
    G.bfs(2);

    // Gracefully exit
    return 0;
}