// Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

// Example 1:

// Input:
// N = 4
// inorder[] = {1 6 8 7}
// preorder[] = {1 6 7 8}
// Output: 8 7 6 1
// Probelm Link: https://practice.geeksforgeeks.org/problems/construct-tree-1/1#
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    map<int,int> m;
    int i=0;
    Node* helper(int pre[],int lb,int ub){
        if(lb>ub)
            return NULL;
        int mid=m[pre[i]];
        Node* res=new Node(pre[i++]);

        if(lb==ub)
            return res;
        
        res->left=helper(pre,lb,mid-1);
        res->right=helper(pre,mid+1,ub);
        return res;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        i=0;
        m.clear();
        for(int i=0;i<n;i++)
            m[in[i]]=i;
        return helper(pre,0,n-1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}