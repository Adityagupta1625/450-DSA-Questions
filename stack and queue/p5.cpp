#include <iostream>
#include <stack>
using namespace std;
stack<int> rev_stack(stack<int> s,int x){
    if(s.empty()){
        s.push(x);
    }
    else{
        int a=s.top();
        s.pop();
        rev_stack(s,a);
        s.push(x);
    }
    return s;
}

int main()
{
    stack<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);
    }

    s=rev_stack(s,s.top());
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}