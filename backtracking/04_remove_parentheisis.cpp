// Remove Parentheis

//Probelm Link: https://leetcode.com/problems/remove-invalid-parentheses/submissions/ 

class Solution {

private:
    int minremoval(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty() || st.top()==')')
                    st.push(s[i]);
                else if(st.top()=='(')
                    st.pop();
            }
        }
        return st.size();
    }
    bool isbalanced(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty() || st.top()==')')
                    st.push(s[i]);
                else if(st.top()=='(')
                    st.pop();
            }
        }
        return st.size()==0;
    }
    void solve(string s,vector<string>& ans,int n,int rev,map<string,int>& m){
        if(m[s]==1)
            return;
        m[s]=1;
        if(rev==0 && isbalanced(s)){
            ans.push_back(s);
            
            return;
        }
        
        for(int i=0;i<s.length();i++){
            if(s[i]!='(' && s[i]!=')')
                continue;
            string prefix=s.substr(0,i);
            string left=s.substr(i+1);
            solve(prefix+left,ans,n,rev-1,m);
        }
        
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int min=minremoval(s);
        int n=s.length();
        map<string,int> m;
        set<string> p;
        solve(s,ans,n,min,m);
        return ans;
    }
};