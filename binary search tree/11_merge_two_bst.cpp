#include <iostream>
#include <vector>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
public:
    int data;
    node *left;
    node *right;
};

void store(node *root1, vector<int> &v)
{
    if (!root1)
        return;

    store(root1->left, v);
    v.push_back(root1->data);
    store(root1->right, v);
}
void merge(vector<int> v1, vector<int> v2, vector<int> &v3)
{
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            v3.push_back(v1[i]);
            i++;
      
        }
        else
        {
            v3.push_back(v2[j]);
            j++;
            
        }
    }
    while (i < v1.size())
    {

        v3.push_back(v1[i]);
        i++;
    }
    while (j < v2.size())
    {

        v3.push_back(v2[j]);
        j++;
       
    }
}
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}
node *helper(vector<int> v, int l, int h)
{
    if (l > h)
        return NULL;

    int m = (l + h) / 2;
    node *root = newNode(v[m]);
    if (l == h)
        return root;

    root->left = helper(v, l, m - 1);
    root->right = helper(v, m + 1, h);
    return root;
}
node *mergeTrees(node *root1, node *root2, int m, int n)
{
    vector<int> v1, v2, v3;

    store(root1, v1);
    store(root2, v2);
    
    merge(v1, v2, v3);
    
    node *root3 = helper(v3, 0, v3.size() - 1);
    return root3;
}

/* Helper function that allocates
a new node with the given data and
NULL left and right pointers. */

// A utility function to print inorder
// traversal of a given binary tree
void printInorder(node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

/* Driver code*/
int main()
{
    /* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    node *root1 = newNode(100);
    root1->left = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);

    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    node *root2 = newNode(80);
    root2->left = newNode(40);
    root2->right = newNode(120);

    node *mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);

    return 0;
}