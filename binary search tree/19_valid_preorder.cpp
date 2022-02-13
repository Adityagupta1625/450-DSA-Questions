Node* post_order(int pre[], int size)
{
    //code here
    stack<Node*> st;
    Node* root=newNode(pre[0]);
    st.push(root);
    for(int i=1;i<size;i++){
        Node* tmp=NULL;
        Node* n=newNode(pre[i]);
        while(!st.empty() && st.top()->data<pre[i]){
            tmp=st.top();
            st.pop();
        }
        if(tmp!=NULL){
            tmp->right=n;
            st.push(tmp->right);
        }
        else{
            st.top()->left=n; 
            st.push(st.top()->left);
        }
        
    }
    return root;
}