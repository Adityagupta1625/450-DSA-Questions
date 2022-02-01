// word break probelm 

// probelm link: https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

class Solution {
private:
    void solve(string s,vector<string>& wordDict,string str,vector<string>& ans){
        if(s.length()==0){
            str.pop_back();
            ans.push_back(str);
            return;
        }
        for(int i=0;i<s.length();i++){
            string used=s.substr(0,i+1);
            string left=s.substr(i+1);
            if(find(wordDict.begin(),wordDict.end(),used)!=wordDict.end()){
                solve(left,wordDict,str+used+" ",ans);
            }
        }
        
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string str="";
        solve(s,wordDict,str,ans);
        return ans;
    }
};