#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;
 
// A class that represents an undirected graph
class Graph
{
// No. of vertices
    int V;
 
    // A dynamic array of adjacency lists
    list<int> *adj;
public:
 
    // Constructor and destructor
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph()
    {
        delete [] adj;
    }
 
    // functions to add and remove edge
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    void rmvEdge(int u, int v);
 
    // Methods to print Eulerian tour
    void printEulerTour();
    void printEulerUtil(int s);
 
    // This function returns count of vertices
    // reachable from v. It does DFS
    int DFSCount(int v, bool visited[]);
 
    // Utility function to check if edge u-v
    // is a valid next edge in Eulerian trail or circuit
    bool isValidNextEdge(int u, int v);
};
 
void Graph::printEulerTour()
{
   
}
 
// Print Euler tour starting from vertex u
void Graph::printEulerUtil(int u)
{
 
    
}

bool Graph::isValidNextEdge(int u, int v)
{
 
 
}
 

void Graph::rmvEdge(int u, int v)
{
   
}
 

int Graph::DFSCount(int v, bool visited[])
{
   
}
 
// Driver program to test above function
int main()
{
    // Let us first create and test
    // graphs shown in above figure
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.printEulerTour();
 
    Graph g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 0);
    g3.addEdge(2, 3);
    g3.addEdge(3, 1);
 
    // comment out this line and you will see that
    // it gives TLE because there is no possible
    // output g3.addEdge(0, 3);
    g3.printEulerTour();
 
    return 0;
}