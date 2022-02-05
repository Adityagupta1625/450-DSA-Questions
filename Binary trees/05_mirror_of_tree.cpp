// probelm link: https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/
#include <iostream>
using namespace std;
 
// A binary tree node has data, pointer to
// left child and a pointer to right child
typedef struct treenode {
    int val;
    struct treenode* left;
    struct treenode* right;
} node;
 
// Helper function that allocates a new node with the
// given data and NULL left and right pointers
node* createNode(int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
// Helper function to print Inorder traversal
void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout <<" "<< root->val;
    inorder(root->right);
}
 
// recursive approach 
// void mirrorify(node* root, node** mirror)
// {
//   if(root==NULL){
//       mirror=NULL;
//       return;
//   }
//   *mirror=createNode(root->val);
//   mirrorify(root->left,&(*mirror)->right);
//   mirrorify(root->right,&(*mirror)->left);
// }
 
// swap approach
node* mirrorify(node* root)
{
  if(root==NULL){
      return root;
  }
  node* t=root->left;
  root->left=root->right;
  root->right=t;

  if(root->left!=NULL)
    mirrorify(root->left);
  if(root->right!=NULL)
    mirrorify(root->right);

  return root;
}
// Driver code
int main()
{
 
    node* tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);
 
    // Print inorder traversal of the input tree
    cout <<"Inorder of original tree: ";
    inorder(tree);
    node* mirror = NULL;
    // mirrorify(tree, &mirror);
    tree=mirrorify(tree);
    // Print inorder traversal of the mirror tree
    cout <<"\nInorder of mirror tree: ";
    inorder(tree);
 
    return 0;
}