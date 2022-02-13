class Solution
{
public:
    Node* succ=NULL;
    void populateNext(Node *root)
    {
        //code here
        if(!root) return;
        
        populateNext(root->right);
        
        root->next=succ;
        succ=root;
        populateNext(root->left);
        
    }
};