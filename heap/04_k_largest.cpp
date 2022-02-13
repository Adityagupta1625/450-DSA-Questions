class Solution{
public:
    int partion(int arr[],int l,int r){
        int x=arr[r];
        int j=l;
        for(int i=l;i<=r;i++){
            if(x>=arr[i]){
                swap(arr[i],arr[j]);
                j++;
            }
        }
        swap(arr[j],arr[r]);
        return j;
    }
    int randompartion(int arr[],int l,int r){
        int n=r-l+1;
        int pivot=rand()%n;
        swap(arr[l+pivot],arr[r]);
        return partion(arr,l,r);
    }
    vector<int> quickSelect(int arr[],int l,int r,int k,int n){
        if(k>0 && k<=r-l+1){
            int pivot=randompartion(arr,l,r);
            
            if(pivot==k){
                vector<int> ans;
                
                for(int i=n-pivot;i<n;i++){
                    ans.push_back(arr[i]);
                }
                return ans;
            }
            else if(pivot-l>k-1)
                return quickSelect(arr,l,pivot-1,k,n);
            return quickSelect(arr,pivot+1,r,k+l-pivot-1,n);
        }
        return {0};
    }
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	   vector<int> ans=quickSelect(arr,0,n-1,k,n);
	
	   return ans;
	}

};