int c=0;
void helper(Node* root,int l,int h){
    if(!root) return;
    
    if(root->data>=l && root->data<=h){
        c++;
        helper(root->left,l,h);
        helper(root->right,l,h);
    }
    else if(root->data>h){
        
        helper(root->left,l,h);
    }
    else if(root->data<l){
        
        helper(root->right,l,h);
    }
    return;
}
int getCount(Node *root, int l, int h)
{
  // your code goes here 
  c=0;
  helper(root,l,h);
  return c;
}