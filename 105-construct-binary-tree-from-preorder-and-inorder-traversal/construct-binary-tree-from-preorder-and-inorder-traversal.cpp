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
        TreeNode* build(vector<int>& preorder,vector<int>& inorder,int& preindex,int instart,int inend,unordered_map<int,int>& mp){
        if(instart>inend) return nullptr;
        int rootVal=preorder[preindex++];
        TreeNode* root=new TreeNode(rootVal);
        int inindex=mp[rootVal];
        root->left=build(preorder,inorder,preindex,instart,inindex-1,mp);
        root->right=build(preorder,inorder,preindex,inindex+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        int preindex=0;
        return build(preorder,inorder,preindex,0,inorder.size()- 1,mp);
    }
};