#include <iostream>
#include <stack>
using namespace std;

// A tree node
struct Node
{

    int data;
    Node *left, *right;
};

// Function to create a new node with the given data
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// An iterative function to do post order
// traversal of a given binary tree

// two stack method
// void postOrderIterative(Node* root)
// {
//     if (root == NULL)
//         return;

//     stack<Node* >s1,s2;
//     Node* root=root;
//     s1.push(root);
//     while(!s1.empty()){
//         Node* tmp=s1.top();
//         s1.pop();
//         s2.push(tmp);
//         if(tmp->left!=NULL)
//             s1.push(tmp->left);
//         if(tmp->right!=NULL)
//             s1.push(tmp->right);
//     }
//     while(!s2.empty()){
//         cout<<s2.top()->data<<" ";
//         s2.pop();
//     }
// }

// one stack method
void postOrderIterative(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    

    do
    {
        while (root != NULL)
        {
            if (root->right != NULL)
                st.push(root->right);
            st.push(root);
            root = root->left;
        }
        root = st.top();
       
        st.pop();
        if (root->right != NULL && root->right == st.top() && !st.empty())
        {
            
            st.pop();
            st.push(root);
            root = root->right;
        }
        else
        {
            cout << root->data << " ";
            root = NULL;
        }
    } while (st.size());
}

// Driver code
int main()
{
    // Let us construct the tree
    // shown in above figure
    Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    postOrderIterative(root);

    return 0;
}