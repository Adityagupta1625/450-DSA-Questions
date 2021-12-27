// Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

// SET x y : sets the value of the key x with value y
// GET x : gets the key of x if present else returns -1.

// The LRUCache class has two methods get() and set() which are defined as follows.

// get(key)   : returns the value of the key if it already exists in the cache otherwise returns -1.
// set(key, value) : if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
// In the constructor of the class the capacity of the cache should be intitialized.
 

// Example 1:

// Input:
// cap = 2
// Q = 2
// Queries = SET 1 2 GET 1
// Output: 2
// Explanation: 
// Cache Size = 2

// SET 1 2 GET 1
// SET 1 2 : 1 -> 2

// GET 1 : Print the value corresponding
// to Key 1, ie 2
// Probelm Link: https://practice.geeksforgeeks.org/problems/lru-cache/1#
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
        int size;
        list<pair<int,int>> dq;
        unordered_map<int,list<pair<int,int>>::iterator> m;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        size=cap;
        // code here
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(m.find(key)!=m.end()){
            auto it=m[key];
            pair<int,int> p=*it;
            dq.erase(m[key]);
            dq.push_front(p);
            m[key]=dq.begin();
            return p.second;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(m.find(key)!=m.end()){
            dq.erase(m[key]);
            dq.push_front({key,value});
            m[key]=dq.begin();
        }
        else{
            if(dq.size()==size){
                m.erase(dq.back().first);
                dq.pop_back();
               
            }
            dq.push_front({key,value});
            m[key]=dq.begin();
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}