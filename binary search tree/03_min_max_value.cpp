// Function to find the minimum element in the given BST.
int minValue(Node* root) {
    // Code here
    
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}