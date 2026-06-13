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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0;
        int l2=0;
        ListNode* a=headA;
        ListNode* b=headB;
        while(a){
            l1++;
            a=a->next;
        }
        while(b){
            l2++;
            b=b->next;
        }
        a=headA;
        b=headB;
        int n=abs(l1-l2);
        if(l1>l2){
            while(n--){
                a=a->next;
            }
        }
        else{
            while(n--){
                b=b->next;
            }
        }
        while(a && b){
            if(a==b) return a;
            a=a->next;
            b=b->next;
        }
        return nullptr;

    }
};