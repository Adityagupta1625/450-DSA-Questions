class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    Node* prev=NULL;
    bool isbstutil(Node* root){
        if(root==NULL) return true;
        
        if(!isbstutil(root->left)) return false;
        
        if(prev!=NULL && prev->data>=root->data)
            return false;
        
        prev=root;
        return isbstutil(root->right);
        
    }
    bool isBST(Node* root) 
    {
        // 
        return isbstutil(root);
    }   
};
