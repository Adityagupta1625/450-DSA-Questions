// There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers

// Examples: 
// Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9} 
// Output : 1 2 4 5 
// First meeting [1, 2] 
// Second meeting [3, 4] 
// Fourth meeting [5, 7] 
// Fifth meeting [8, 9]

// Input : s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924}, 
// f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 } 
// Output : 6 7 1 
// Probelm Link: https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Function for finding maximum meeting in one room
void maxMeetings(int s[], int f[], int n)
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({f[i],i});
    }
    sort(v.begin(),v.end());

    vector<int> m;
    int time=v[0].first;
    m.push_back(v[0].second+1);

    for(int i=1;i<n;i++){
        if(time<=s[v[i].second]){
            m.push_back(v[i].second+1);
            time=v[i].first;
        }
    }
    for(int i=0;i<m.size();i++)
        cout<<m[i]<<" ";
}
 
// Driver code
int main()
{
    // Starting time
    int s[] = { 1, 3, 0, 5, 8, 5 };
 
    // Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };
 
    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);
 
    // Function call
    maxMeetings(s, f, n);
 
    return 0;
}