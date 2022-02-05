// Probelm link: https://leetcode.com/problems/clone-graph/
class Solution {
    
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<Node*,Node*> m;
        
        m[node]=new Node(node->val);
        
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            
            Node* n=m[curr];
            for(auto x: curr->neighbors){
                if(m.find(x)!=m.end())
                    (n->neighbors).push_back(m[x]);
                else{
                    Node* newNode=new Node(x->val);
                    m[x]=newNode;
                    q.push(x);
                    (n->neighbors).push_back(newNode);       
                }
            }
            
        }
        return m[node];
    }
};