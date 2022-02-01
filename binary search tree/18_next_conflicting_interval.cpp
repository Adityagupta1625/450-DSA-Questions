#include <iostream>
using namespace std;

// Structure to represent an interval
struct Interval
{
    int low, high;
};

// Structure to represent a node in Interval Search Tree
struct ITNode
{
    Interval *i; // 'i' could also be a normal variable
    int max;
    ITNode *left, *right;
};

ITNode *newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
    return temp;
};

ITNode *insert(ITNode *root, Interval i)
{
    if (root == NULL)
        return newNode(i);

    int l = root->i->low;

    if (i.low < l)
    {
        root->left = insert(root, i);
    }
    else
    {
        root->right = insert(root, i);
    }
    if (root->max < i.high)
        root->max = i.high;

    return root;
}

bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low < i2.high && i2.low < i1.high)
        return true;
    return false;
}

Interval *overlapSearch(ITNode *root, Interval i)
{
    if(!root) return NULL;

    if(doOVerlap(*(root->i),i)) return root->i;

    if(root->left!=NULL && root->left->max>=i.low)
        return overlapSearch(root->left,i);
    
    return overlapSearch(root->right,i);
    
}
void preorder(ITNode* root){
    if(!root) return;

    cout<<(root->i->low)<<" "<<(root->i->high)<<endl;
    preorder(root->left);
    preorder(root->right);
}
void printConflicting(Interval appt[], int n)
{
    ITNode *root = NULL;
    root = insert(root, appt[0]);
    for (int i = 1; i < n; i++)
    {
        // Interval *res = overlapSearch(root, appt[i]);
        // if (res != NULL)
        // {
        //     cout << "[" << appt->low << "-" << appt->high << "]"
        //          << "conflicts"
        //          << "[" << res->low << "-" << res->high << "]";
        // }
        root = insert(root, appt[i]);
    }
  
    preorder(root);
}

// Driver program to test above functions
int main()
{
    // Let us create interval tree shown in above figure
    Interval appt[] = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(appt) / sizeof(appt[0]);
    cout << "Following are conflicting intervals\n";
    printConflicting(appt, n);
    return 0;
}