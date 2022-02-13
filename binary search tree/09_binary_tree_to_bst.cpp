class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    int ind=0;
    Node* helper(vector<int> v,Node* root){
        if(root==NULL)
            return NULL;
            
        helper(v,root->left);
        root->data=v[ind];
        ind++;
        helper(v,root->right);
        
        return root;
    }
    void inorder(Node* root,vector<int> &v){
        if(root==NULL) return;
        inorder(root->left,v);
        
        v.push_back(root->data);
        
        inorder(root->right,v);
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> v;
        inorder(root,v);
        
        sort(v.begin(),v.end());
        
       
        helper(v,root);
        return root;
        
    }
};