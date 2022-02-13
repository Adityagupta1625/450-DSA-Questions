class Solution {
public:
    struct key{
        int freq;
        char c;
        
        bool operator<(const key& k)const {
            return freq<k.freq;
        }
    };
   
    string reorganizeString(string s) {
        map<char,int> m;
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        
        priority_queue<key> pq;
        float n=s.length();
        for(auto i: m){
            if(i.second>ceil(n/2))
                return "";
            key k;
            k.freq=i.second;
            k.c=i.first;
            pq.push(k);
        }
        string ans;
        key prev;
        prev.c='#';
        prev.freq=-1;
        while(!pq.empty()){
            key k=pq.top();
            ans=ans+k.c;
            pq.pop();
            k.freq--;
            if(prev.freq>0)
                pq.push(prev);
            prev=k;
        }
        return ans;
    }
};