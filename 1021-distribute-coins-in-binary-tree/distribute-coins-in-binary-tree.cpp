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
    int helper(TreeNode* root,int &count){
        if(root==nullptr) return 0;
        int left=helper(root->left,count);
        int right=helper(root->right,count);
        count+=abs(left)+abs(right);
        return root->val+left+right-1;
    }
    int distributeCoins(TreeNode* root) {
        int count=0;
        helper(root,count);
        return count;

    }
};