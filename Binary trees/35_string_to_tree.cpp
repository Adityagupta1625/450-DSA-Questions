// Construct Binary Tree from String with bracket representation
// Probelm link: https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/


#include <iostream>
using namespace std;

// custom data type for tree building
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *constructtree(string s, int &start)
{
    if (s.size() == 0 || start >= s.size())
        return NULL;

    int num = 0;
    while (start < s.size() && s[start] != '(' && s[start] != ')')
    {
        int n = s[start] - '0';
        num = num * 10 + n;
        start++;
    }
    Node *root = new Node(num);

    if (start < s.size() && s[start] == '(')
    {
        start++;
        root->left = constructtree(s, start);
    }
    if (start < s.size() && s[start] == ')')
    {
        start++;
        return root;
    }

    if (start < s.size() && s[start] == '(')
    {
        start++;
        root->right = constructtree(s, start);
    }
    if (start < s.size() && s[start] == ')')
    {
        start++;
    }
    return root;
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    string s = "4(2(3)(1))(6(5))";
    // cin>>s;
    int start = 0;
    Node *root = constructtree(s, start);
    preorder(root);
    return 0;
}