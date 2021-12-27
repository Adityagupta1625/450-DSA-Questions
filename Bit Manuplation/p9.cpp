#include <iostream>
using namespace std;
// void copySetBits(int x,int y,int l,int r){
//     if(l<1 || r>32)
//         return;
//     for (int i = l; i <=r; i++)
//     {
//         int mask=1<<(i-1);
//         if(y&mask)
//             x=x|mask;
        
//     }
//     cout<<x<<endl;
// }

void copySetBits(int x,int y,int l,int r){
    if(l<1 || r>32)
        return;
    int masklen=(1ll<<(r-l+1))-1;
    int mask=(masklen<<(l-1))&y;
    x=x|mask;
    cout<<x<<endl;
}
int main()
{   
    unsigned x = 10, y = 13, l = 2, r = 3;
   copySetBits(x, y, l, r);
//    cout << "Modified x is " << x;
    return 0;
}
