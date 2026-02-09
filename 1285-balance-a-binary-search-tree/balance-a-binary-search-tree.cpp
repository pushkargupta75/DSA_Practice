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
    TreeNode* construct(vector<int>& inorder,int start,int end){
        if(start>end) return nullptr;
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(inorder[mid]);
        root->left=construct(inorder,start,mid-1);
        root->right=construct(inorder,mid+1,end);
        return root;
    }
    void inorder_traversal(TreeNode* root,vector<int>& inorder){
        if(!root) return;
        inorder_traversal(root->left,inorder);
        inorder.push_back(root->val);
        inorder_traversal(root->right,inorder);
    }
    TreeNode* balanceBST(TreeNode* root) {
       vector<int> inorder;
       inorder_traversal(root,inorder);
       TreeNode* ans=construct(inorder,0,inorder.size()-1);
       return ans; 
    }
};