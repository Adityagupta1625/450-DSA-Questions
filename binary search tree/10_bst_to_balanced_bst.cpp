void inorder(Node* root,vector<int> &v){
    if(root==NULL) 
        return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
Node* convert(vector<int> v,int l,int h){
    if(l>h)
        return NULL;
        
    int m=(l+h)/2;
    Node* root=new Node(v[m]);
    
    if(l==h)
        return root;
    root->left=convert(v,l,m-1);
    root->right=convert(v,m+1,h);
    return root;
}
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> v;
	inorder(root,v);

	int l=0,h=v.size()-1;
	root=convert(v,l,h);
	return root;
}