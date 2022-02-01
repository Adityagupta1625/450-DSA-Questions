//     10
//    /   \
//   5     40
//  /  \      \
// 1    7      50

// 10 5 1 7 40 50

#include <iostream>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
    int data;
    node* left;
    node* right;
};
 
// A utility function to create a node
node* newNode(int data)
{
    node* temp = new node();
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
// O(n^2) approach 
// int ind=0;
// node* helper(int pre[],int l,int h,node* root,int size){
//     if(ind>=size || l>h)
//         return NULL;

//     root=newNode(pre[ind]);
//     ind++;

//     if(l==h)
//         return root;

//     int j;
//     for(j=l;j<=h;j++){
//         if(root->data<pre[j])
//             break;
//     }    
//     root->left=helper(pre,ind,j-1,root,size);
//     root->right=helper(pre,j,h,root,size);

//     return root;
// }

// node* constructTree(int pre[], int size)
// {
//     node* root=NULL;
//     root=helper(pre,0,size-1,root,size);
//     return root;
// }
 
// O(n)
int ind=0; 
node* helper(int pre[],int size,node* root,int min,int max,int key){
    if(ind>=size)
        return NULL;
    root=NULL;
    if(min<key && max>key){
        root=newNode(key);
        ind++;
        
        if(ind<size){
            root->left=helper(pre,size,root,min,root->data-1,pre[ind]);
        }
        if(ind<size){
            root->right=helper(pre,size,root,root->data+1,max,pre[ind]);
        }
    }
    return root;
}
node* constructTree(int pre[], int size)
{   
    node* root=NULL;
    root=helper(pre,size,root,INT_MIN,INT_MAX,pre[0]);    
    return root;
}


void printInorder(node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
 
    node* root = constructTree(pre, size);
 
    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);
 
    return 0;
}
 