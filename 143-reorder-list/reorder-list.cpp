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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp=head;
        while(temp!=nullptr){
            st.push(temp);
            temp=temp->next;
        }
        int k=st.size()/2;
        ListNode* topnode;
        ListNode* curr=head;
        while(k--){
            topnode=st.top();
            st.pop();
            ListNode* temp=curr->next;
            curr->next=topnode;
            topnode->next=temp;
            curr=temp;
        }
        curr->next=nullptr;
    }
};