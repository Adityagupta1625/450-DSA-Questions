void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
    if(root==NULL)
        return;
    
    if(root->key>key){
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else if(root->key<key){
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
    else{
        if(root->left!=NULL){
            Node* tmp=root->left;
            while(tmp->right!=NULL){
                tmp=tmp->right;
            }
            pre=tmp;
        }
        
        if(root->right!=NULL){
            Node* tmp=root->right;
            while(tmp->left!=NULL){
                tmp=tmp->left;
            }
            suc=tmp;
        }
            
    }
}