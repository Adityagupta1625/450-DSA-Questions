class Solution{
    public:
    void heapify(vector<int>& arr,int size,int i){
        int l=2*i+1;
        int r=2*i+2;
        int largest=i;
        if(l<size && arr[largest]<arr[l])
            largest=l;
        if(r<size && arr[largest]<arr[r])
            largest=r;
        
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,size,largest);
        }
    }
    void buildHeap(vector<int>& ans,int size){
        int idx=(size/2)-1;
        for(int i=idx;i>=0;i--){
            heapify(ans,size,i);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(a[i]);
        }
        for(int i=0;i<m;i++){
            ans.push_back(b[i]);
        }
        
        buildHeap(ans,n+m);
        return ans;
    }
};