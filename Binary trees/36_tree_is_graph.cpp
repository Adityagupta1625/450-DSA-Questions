#include<iostream>
#include <list>
#include <limits.h>
#include <vector>
using namespace std;
 
// Class for an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj; // Pointer to an array for adjacency lists
    bool isCyclicUtil(int v, vector<bool>& vis, int parent);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isTree();   // returns true if graph is tree
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}
bool Graph::isCyclicUtil(int v, vector<bool>& vis, int parent){
    vis[v]=true;

    for(auto x: adj[v]){
        if(!vis[x]){
             if(isCyclicUtil(x,vis,v))
                return true;
        }
        else if(x!=parent){
            return true;
        }  
    }
    return false;
} 
bool Graph::isTree(){
    vector<bool> vis;
    for(int i=0;i<V;i++)
        vis.push_back(false);
    
    if(isCyclicUtil(0,vis,-1)){
        return false;
    }

    for(auto x: vis){
        if(x==false)
            return false;
    }
    return true;
}
 

 
// Driver program to test above functions
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    return 0;
}