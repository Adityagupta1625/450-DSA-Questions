class Solution
{
    public:
    //Function to merge k sorted arrays.
    struct triplet{
        int data;
        int idx;
        int j;
    };
    struct compare{
        bool operator()(triplet t1,triplet t2){
            return t1.data>t2.data;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<triplet,vector<triplet>,compare> pq;
        
        for(int i=0;i<K;i++){
            triplet t;
            t.data=arr[i][0];
            t.idx=i;
            t.j=0;
            pq.push(t);
        }
        
        vector<int> ans;
        while(!pq.empty()){
          triplet t=pq.top();
          pq.pop();
           
          int idx=t.idx;
          int data=t.data;
          int j=t.j;
           
          ans.push_back(data);
           
          if(j+1<K){
                 triplet n;
                n.data=arr[idx][j+1];
                n.idx=idx;
                 n.j=j+1;
                pq.push(n);
          }
         
        }
        return ans;
    }
};