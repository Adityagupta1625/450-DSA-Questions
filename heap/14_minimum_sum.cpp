
class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string a,b;
        for(int i=0;i<n;i++){
            if((i+1)%2==0)
                a=a+to_string(arr[i]);
            else
                b=b+to_string(arr[i]);
        }
        int i=a.length()-1,j=b.length()-1;
        string c;
        int carry=0;
        
        while(i>=0 && j>=0){
            int sum=((a[i]-'0')+(b[j]-'0'))+carry;
           
            c=c+to_string(sum%10);
            carry=sum/10;
            i--;
            j--;
        }
        
        while(i>=0){
            int sum=(a[i]-'0')+carry;
            carry=sum/10;
          
            c=c+to_string(sum%10);
            i--;
        }
        
        while(j>=0){
            int sum=(b[j]-'0')+carry;
            carry=sum/10;
            
            c=c+to_string(sum%10);
            j--;
        }
        
        while(carry){
            c=c+to_string(carry%10);
            carry=carry/10;
        }
        
        reverse(c.begin(),c.end());
        int k=0;
        while(k<c.length() && c[k]=='0'){
            k++;
        }
            
        return c.substr(k,c.length());
    }
};