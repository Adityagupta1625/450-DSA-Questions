// Min max in optimised way 

#include <iostream>
using namespace std;
class minmax{
    public:
        int max;
        int min;
        void findminmax(int arr[],int n);     
};
void minmax::findminmax(int arr[],int n){
    if (n==1)
    {
        max=arr[0];
        min=arr[0];
        cout<<max<<" "<<min<<endl;
    }
    if(arr[0]>arr[1]){
        max=arr[0];
        min=arr[1];
    }
    if(arr[0]<arr[1]){
        max=arr[1];
        min=arr[0];

    }
    for (int i = 2; i < n; i++)
    {
        if (max>arr[i])
        {
            max=arr[i];
        }
        else if (min<arr[i])
        {
            min=arr[i];
        }
        
    }
    cout<<"Max Value is: "<<max<<endl;
    cout<<"Min Value is: "<<min<<endl;

}
int main()
{
    int arr[]={1,2,5,6,7,8,14,7,65};
    minmax m;
    int n=9;
    m.findminmax(arr,n);
    return 0;
}