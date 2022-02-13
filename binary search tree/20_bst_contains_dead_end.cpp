bool helper(Node* root,int l,int h){
    if(!root) return false;
    
    
    if(l==h) return true;
    
    return helper(root->left,l,root->data-1) ||
           helper(root->right,root->data+1,h);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    return helper(root,1,200);
}