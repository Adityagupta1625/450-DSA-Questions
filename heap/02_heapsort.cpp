class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
        int l=2*i+1;
        int r=2*i+2;
        
        int largest=i;
        
        if(l<n && arr[largest]>arr[l])
            largest=l;
        if(r<n && arr[largest]>arr[r])
            largest=r;
        
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        int idx=(n/2)-1;
        for(int i=idx;i>=0;i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        
    }
};