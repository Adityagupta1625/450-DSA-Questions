class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> helper(Node* root){
        if(!root) return {1,0,INT_MAX,INT_MIN};
        
        if(!root->left && !root->right) return {1,1,root->data,root->data};
        
        vector<int> a=helper(root->left);
        vector<int> b=helper(root->right);
        
        if(a[0]==1 && b[0]==1){
            
            if(root->data>a[3] && root->data<b[2]){
                int x=a[2];
                int y=b[3];
                
                if(x==INT_MAX) x=root->data;
                
                if(y==INT_MIN) y=root->data;
                
                return {1,1+a[1]+b[1],x,y};
            }
            
        }
        return {0,max(a[1],b[1]),0,0};
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	vector<int> v=helper(root);
    	return v[1];
    }
};