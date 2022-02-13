class Solution
{
public:
    void find(Node* root,vector<int> &v){
        if(!root) return;
        
        find(root->left,v);
        v.push_back(root->data);
        find(root->right,v);
        return;
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int> v1,v2;
        find(root1,v1);
        find(root2,v2);
        
        int n=v1.size();
        int m=v2.size();
        
        int i=0,j=m-1;
        int cnt=0;
        while(i<n && j>=0){
            if(v1[i]+v2[j]<x)
                i++;
            else if(v1[i]+v2[j]>x)
                j--;
            else{
                i++;
                j--;
                cnt++;
            }
        }
        return cnt;
    }
};