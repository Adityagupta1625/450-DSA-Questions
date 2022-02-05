// Probelm link: https://leetcode.com/problems/word-ladder/

class Solution {

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string> wordSet(wordList.begin(), wordList.end());
        map<string,int> vis;
        queue<pair<string,int>> q;
        
        q.push({beginWord,1});
        while(!q.empty()){
            string s=q.front().first;
            int dist=q.front().second;
            q.pop();
            
            if(s==endWord)
                return dist;
            
           
            for(int i=0;i<s.length();i++){
                string temp=s;
                for(char c='a';c<='z';c++){
                    if(s[i]!=c){
                        temp[i]=c;
                        if(wordSet.find(temp)!=wordSet.end() &&                                   (vis[temp]==0 || 
                          vis.find(temp)==vis.end())){
                            vis[temp]=1;
                            q.push({temp,dist+1});
                        }
                      
                }
                temp[i]=s[i];
            }
        }
    }
    return 0;
    }
};