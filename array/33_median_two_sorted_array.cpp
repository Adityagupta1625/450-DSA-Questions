#include <iostream>
using namespace std;
int getMedian(int a[],int b[],int n){
    int i=0,j=0;
    for (int count = 0; count < n; count++)
    {
        if (a[i]<b[j])
        {
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
        
    }
    
    return 0;
}
int main()
{
    int ar1[] = { 1, 12, 15, 26, 38 };
    int ar2[] = { 2, 13, 17, 30, 45 };
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is " << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays"
             << " of unequal size";
    getchar();
    return 0;
}