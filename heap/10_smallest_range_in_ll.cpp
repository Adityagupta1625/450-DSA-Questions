class Solution{
    public:
    struct comp{
        bool operator()(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2){
            return p1.first>p2.first;
        }
    };
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          pair<int,int> ans;
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
          comp> pq;
          
          int mx=INT_MIN,mi=INT_MAX;
          for(int i=0;i<k;i++){
              pq.push({arr[i][0],{i,0}});
              mx=max(mx,arr[i][0]);
              mi=min(mi,arr[i][0]);
          }
          ans={mi,mx};
          while(true){
              int x=pq.top().first;
              pair<int,int> idx=pq.top().second;
              int i=idx.first;
              int j=idx.second;
              pq.pop();
              
              if(j+1>=n){
                  break;
              }
              int ele=arr[i][j+1];
              mx=max(mx,ele);
              mi=min(ele,pq.top().first);
              
              if(ans.second-ans.first>mx-mi){
                  ans.first=mi;
                  ans.second=mx;
              }
              pq.push({ele,{i,j+1}});        
          }
          
          return ans;
    }
};