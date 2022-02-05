// Find largest subtree sum in a tree

// Given a binary tree, task is to find subtree with maximum sum in tree.
// Examples: 
 

// Input :       1
//             /   \
//            2      3
//           / \    / \
//          4   5  6   7
// Output : 28
// As all the tree elements are positive,
// the largest subtree sum is equal to
// sum of all tree elements.
// Probelm Link: https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/

#include <iostream>
#include <algorithm>
using namespace std;
 
// Structure of a tree node.
struct Node {
    int key;
    Node *left, *right;
};
 
// Function to create new tree node.
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

int helper(Node* root, int& ans)
{
    if(root==NULL)
        return 0;
    
    int sum=root->key+helper(root->left,ans)+helper(root->right,ans);

    ans=max(sum,ans);

    return sum;
}
 
// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{
    int ans=INT_MIN;
    helper(root,ans);
    return ans;
}
 
// Driver function
int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
 
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
 
    cout << findLargestSubtreeSum(root);
    return 0;
}