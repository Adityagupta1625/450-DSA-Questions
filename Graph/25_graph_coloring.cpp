#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// A class that represents an undirected graph
class Graph
{
    int V;          // No. of vertices
    list<int> *adj; // A dynamic array of adjacency lists
public:
    // Constructor and destructor
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph() { delete[] adj; }

    // function to add an edge to graph
    void addEdge(int v, int w);

    // Prints greedy coloring of the vertices
    void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v); // Note: the graph is undirected
}

// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors
void Graph::greedyColoring()
{
    vector<bool> avail(V, false);
    vector<int> result(V, -1);

    result[0] = 0;

    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            if (result[x] != -1)
            {
                avail[result[x]] = true;
            }
        }

        int a;
        for (int i = 0; i < V; i++)
        {
            if (avail[i] == false)
            {
                a = i;
                break;
            }
        }

        result[i] = a;

        for (auto x : adj[i])
        {
            if (result[x] != -1)
                avail[result[x]] = false;
        }
    }
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;
}

// Driver program to test above function
int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Coloring of graph 1 \n";
    g1.greedyColoring();

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\nColoring of graph 2 \n";
    g2.greedyColoring();

    return 0;
}