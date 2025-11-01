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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(),nums.end());
        ListNode*temp=head;
        while(head!=nullptr && s.find(head->val)!=s.end()){
            head=head->next;
        }
        while(temp!=nullptr && temp->next!=nullptr){
            if(s.contains(temp->next->val)) temp->next=temp->next->next;
            else temp=temp->next;
        }
        return head;
    }
    
};