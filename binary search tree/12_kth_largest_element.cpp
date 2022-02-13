class Solution
{
    public:
    int t=1;
    int kthLargest(Node *root, int k)
    {
        
        if(!root)
            return -1;
        
        int f=kthLargest(root->right,k);
        if(f!=-1)
            return f;
        
        
        if(k==t)
            return root->data;
        t++; 
        return kthLargest(root->left,k);
    }
};