class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long int, vector<long long int>, greater<long long int> > q;
        
        for(int i=0;i<n;i++)
            q.push(arr[i]);
            
        long long a,b;
        long long sum=0;
        while(q.size()>1){
            a=q.top();
            q.pop();
            b=q.top();
            q.pop();
            sum+=(a+b);
            q.push(a+b);
        }
        
        return sum;
    }
};