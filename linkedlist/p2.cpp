// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

// Probelm link: https://leetcode.com/problems/middle-of-the-linked-list/

#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *ptr=head;
        int cnt=0;
        while(ptr!=NULL){
            ptr=ptr->next;
            cnt++;
        }
        int t=0;
        ptr=head;
        if(cnt%2==0){
           while(t<cnt/2){
             t++;
             head=head->next;
          } 
        }
        else{
            while(t<cnt/2){
             t++;
             head=head->next;
          }
        }
        return head;
    }
};
int main()
{
 
return 0;
}