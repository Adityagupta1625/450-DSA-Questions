class Solution{
  public:
    //Function to merge K sorted linked list.
     struct compare{
        
        bool operator()(struct Node* a,struct Node* b){
            return a->data>b->data;
        }
    };
    Node * mergeKLists(Node *arr[], int K)
    {
          priority_queue<Node*,vector<Node*>,compare> pq;
          for(int i=0;i<K;i++){
              pq.push(arr[i]);
          }
          
          Node* newhead=NULL;
          Node* prev;
          while(!pq.empty()){
              Node* tmp=pq.top();
              pq.pop();
              
              if(tmp->next!=NULL)
                    pq.push(tmp->next);
                    
              if(newhead==NULL){
                  newhead=tmp;
                  prev=tmp;
                  tmp->next=NULL;
              }
              else{
                  prev->next=tmp;
                  tmp->next=NULL;
                  prev=tmp;
              }
          }
          return newhead;
    }
};