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
    void helper(TreeNode* root,string &t,vector<string>& v){
        if(root==nullptr) return;
        t+=(root->val+'0');
        if(!root->left && !root->right) v.push_back(t);
        
        helper(root->left,t,v);
        helper(root->right,t,v);
        t.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string t="";
        vector<string> v;
        helper(root,t,v);
        int ans=0;
        for(int i=0;i<v.size();i++) ans+=stoi(v[i]);
        return ans;

    }
};