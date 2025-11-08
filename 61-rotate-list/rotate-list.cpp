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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head||!head->next) return head;
        int n=0;
        ListNode* temp=head;
        ListNode* temp2=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0) return head;
        temp=head;
        while(temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=head;
        int i=0;
        while(i<n-k-1){
            temp2=temp2->next;
            i++;
        }
        head=temp2->next;
        temp2->next=NULL;
        return head;
    }
};