class Solution {
public:
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->right==NULL && root->left==NULL)
                return NULL;
            
            else if(root->left==NULL){
                root=root->right;
                return root;
            }
            
            else if(root->right==NULL){
                root=root->left;
                return root;
            }
            else{
               TreeNode* succParent=root;
               TreeNode* tmp=root->right;
               while(tmp->left!=NULL){
                   succParent=tmp;
                   tmp=tmp->left;
               }
                
               if(succParent!=root){
                   succParent->left=tmp->right;
               }
               else{
                   succParent->right=tmp->right;
               }
                
                root->val=tmp->val;
                return root;
            }
        }
        return root;
    }
};