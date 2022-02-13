class Solution {
  public:
    
    int countNodes(struct Node* root){
        if(!root) return 0;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    bool isComplete(struct Node* root,int cnt,int index){
        if(!root) return true;
        
        if(index>=cnt) return false;
        
        return isComplete(root->left,cnt,2*index+1) 
               && isComplete(root->right,cnt,2*index+2);
    }
    bool helper(struct Node* root){
        if(!root) return true;
        
        if(!root->left && !root->right) return true;
        
        if(!root->left || !root->right) return true;
        
        if(root->data>root->left->data && root->data>root->right->data)
            return (isHeap(root->left) && isHeap(root->right));
        return false;
    }
    bool isHeap(struct Node* root) {
        // code here
        int cnt=countNodes(root);
        return isComplete(root,cnt,0) && helper(root);
    }
};