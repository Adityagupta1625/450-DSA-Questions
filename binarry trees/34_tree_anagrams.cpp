#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int data;
};
 
// Returns true if trees with root1 and root2
// are level by level anagram, else returns false.
bool areAnagrams(Node *root1, Node *root2)
{
    
    if(!root1 && !root2)
        return true;

    if(!root1 || !root2)
        return false;

    queue<Node*> q1,q2;

    vector<int> v1,v2;

    q1.push(root1);
    q2.push(root2);
    while(!q1.empty() && !q2.empty()){
        if(q1.size()!=q2.size()){
            return false;
        }

        int n=q1.size();
        v1.clear();
        v2.clear();
        while(n--){

            Node* tmp1=q1.front();
            q1.pop();

            Node* tmp2=q2.front();
            q2.pop();

            v1.push_back(tmp1->data);
            v2.push_back(tmp2->data);

            if(tmp1->left)
                q1.push(tmp1->left);
            if(tmp1->right)
                q1.push(tmp1->right);

            if(tmp2->left)
                q2.push(tmp2->left);
            if(tmp2->right)
                q2.push(tmp2->right);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1!=v2)
            return false;
    }
    return true;
}
 
// Utility function to create a new tree Node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Constructing both the trees.
    struct Node* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);
 
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
 
    areAnagrams(root1, root2)? cout << "Yes" : cout << "No";
    return 0;
}