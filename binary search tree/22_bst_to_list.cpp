#include <iostream>
using namespace std;
 
// Node of the binary tree
struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
 

void print(node* parent)
{
    node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}

void inorder(node* curr, node*& prev)
{
   if(!curr) return;
   inorder(curr->left,prev);

   prev->right=curr;
   prev=curr;

   inorder(curr->right,prev);
}
 

node* flatten(node* parent)
{
    node* dummy=new node(-1);

    node* prev=dummy;
    inorder(parent,prev);

    prev->left=NULL;
    prev->right=NULL;

    return dummy->right;

}
 
// Driver code
int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
 
    // Calling required function
    print(flatten(root));
 
    return 0;
}