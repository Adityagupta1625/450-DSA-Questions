#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
struct node
{
    int data;
    int vc;
    struct node *left, *right;
};
void addEdge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

// Approach 1:
// // A memoization based function that returns size of the minimum vertex cover.
// int vCover(struct node *root)
// {
//     if (root == NULL)
//         return 0;

//     if (root->left == NULL && root->right == NULL)
//         return 0;

//     if (root->vc != 0)
//         return root->vc;

//     int size_incl = 1 + vCover(root->left) + vCover(root->right);

//     int size_excl = 0;
//     if (root->left)
//         size_excl += 1 + vCover(root->left->left) + vCover(root->left->right);
//     if (root->right)
//         size_excl += 1 + vCover(root->right->left) + vCover(root->right->right);

//     root->vc = min(size_excl, size_incl);

//     return root->vc;
// }

// Approach 2:
void solve(vector<int> adj[],int curr,vector<int> dp[],int par){
    for(auto x: adj[curr]){
        if(x!=par){
            solve(adj,x,dp,curr);
        }
    }

    for(auto x: adj[curr]){
        if(x!=par){
            dp[curr][0]+=dp[x][1];

            dp[curr][1]+=min(dp[x][0],dp[x][1]);
        }
    }
}
void  minSizeVertexCover(vector<int> adj[],int N){
    vector<int> dp[N+1];

    for(int i=1;i<=N;i++){
        dp[i].push_back(0);
        dp[i].push_back(1);
    }

    solve(adj,1,dp,-1);
    cout<<min(dp[1][0],dp[1][1])<<" ";
}

// A utility function to create a node
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->vc = 0; // Set the vertex cover as 0
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    // struct node *root = newNode(20);
    // root->left = newNode(8);
    // root->left->left = newNode(4);
    // root->left->right = newNode(12);
    // root->left->right->left = newNode(10);
    // root->left->right->right = newNode(14);
    // root->right = newNode(22);
    // root->right->right = newNode(25);

    // printf("Size of the smallest vertex cover is %d ", vCover(root));

    // number of nodes in the tree
    int N = 8;

    // adjacency list representation of the tree
    vector<int> adj[N + 1];

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 7);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 8);
    addEdge(adj, 3, 5);

    minSizeVertexCover(adj, N);

    return 0;
}