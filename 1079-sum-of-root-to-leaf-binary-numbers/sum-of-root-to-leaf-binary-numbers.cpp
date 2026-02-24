/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;
    void helper(TreeNode* root,vector<string> & ans,string temp){
        if(root==nullptr) return;
        temp+=char(root->val+'0');
        if(!root->left && !root->right){
            ans.push_back(temp);
            return;
        }
        
        helper(root->left,ans,temp);
        helper(root->right,ans,temp);
    }
    int sumRootToLeaf(TreeNode* root) {
        string temp="";
        helper(root,ans,temp);
        int a=0;
        for(int i=0;i<ans.size();i++){
            int decimal_val=stoi(ans[i],nullptr,2);
            a+=decimal_val;
        }
        return a;
    }
};