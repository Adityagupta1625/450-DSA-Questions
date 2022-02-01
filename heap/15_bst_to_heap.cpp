#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// structure of a node of BST
struct Node
{
    int data;
    Node *left, *right;
};
 
/* Helper function that allocates a new node
   with the given data and NULL left and right
   pointers. */
struct Node* getNode(int data)
{
    struct Node *getNode = new Node;
    getNode->data = data;
    getNode->left = getNode->right = NULL;
    return getNode;
}
 

void preorderTraversal(Node*);
 
void inorder(Node *root,Node*& prev)
{
    if(!root) return;

    inorder(root->left,prev);

    prev->left=NULL;
    prev->right=root;
    prev=root;

    inorder(root->right,prev);
}

void BSTToMinHeap(Node* &root,Node* head)
{
    if(!head) return;
    
    queue<Node*> q;
    
    root=head;
    head=head->right;
    root->right=NULL;
    
    q.push(root);

    while(head){
        Node* tmp=q.front();
        q.pop();

        Node* l=head;
        head=head->right;
        l->right=NULL;
        tmp->left=l;
        q.push(l);

        if(head){
            Node* r=head;
            head=head->right;
            r->right=NULL;
            tmp->right=r;
            q.push(r);
        }
    }
    preorderTraversal(root);
}
 
// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node *root)
{
    

    Node* head=getNode(-1);
    Node* prev=head;
    inorder(root,prev);
    head=head->right;
    
    root=NULL;
    
    BSTToMinHeap(root,head);
}
 
// function for the preorder traversal of the tree
void preorderTraversal(Node *root)
{
    if (!root)
        return;
 
    // first print the root's data
    cout << root->data << " ";
 
    // then recur on left subtree
    preorderTraversal(root->left);
 
    // now recur on right subtree
    preorderTraversal(root->right);
}
 
// Driver program to test above
int main()
{
    // BST formation
    Node* root = getNode(8);
    root->left = getNode(4);
    root->right = getNode(12);
    root->right->left = getNode(10);
    root->right->right = getNode(14);
    root->left->left = getNode(2);
    root->left->right = getNode(6);
 
    convertToMinHeapUtil(root);
    // cout << "Preorder Traversal:" << endl;
    // preorderTraversal(root);
 
    return 0;
}