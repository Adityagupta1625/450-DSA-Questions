class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int t=1;
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        if(!root) return -1;
        
        int f= KthSmallestElement(root->left,K);
        if(f!=-1)
            return f;
        if(t==K)
            return root->data;
        t++;
        return KthSmallestElement(root->right,K);
    }
};