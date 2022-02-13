   void heapify(int arr[], int n, int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;
        if (l < n && arr[l] > arr[largest])
            largest = l;
        if (r < n && arr[largest] < arr[r])
            largest = r;
    
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void buildHeap(int arr[], int n)
    {
        int idx = (n / 2) - 1;
    
        for (int i = idx; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        
        int n=r-l+1;
        buildHeap(arr,k);
        
        for(int i=k;i<n;i++){
            if(arr[i]<arr[0]){
                arr[0]=arr[i];
                heapify(arr,k,0);
            }
        }
        return arr[0];
    }
};
