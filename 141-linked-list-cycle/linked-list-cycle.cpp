/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* prev = head;
        ListNode* nex = head;
        while(nex!=NULL && nex->next!=NULL){
            prev=prev->next;
            nex=nex->next->next;
            if(prev==nex) return true;
        }
       return false;
    }
};