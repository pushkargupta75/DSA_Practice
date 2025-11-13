/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int k=2;
        ListNode * prevptr=NULL;
        ListNode * current=head;
        int counter=0;
        while(counter<k && current != NULL){
            ListNode * nextptr=current->next;
            current->next=prevptr;
            prevptr=current;
            current=nextptr;
            counter++;
        }
        if(current!=NULL){
        ListNode* new_head=swapPairs(current);
        head->next=new_head;
        }
        return prevptr;
    }
};