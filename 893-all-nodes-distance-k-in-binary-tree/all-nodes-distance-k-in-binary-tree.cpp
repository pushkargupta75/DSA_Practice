/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root, TreeNode* target, unordered_map<TreeNode*,TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                parent_track[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent_track[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;

        markparent(root,target,parent_track);
        
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target]=true;
        int cur_level=0;
        
        while(!q.empty()){
            int si=q.size();
            if(cur_level++==k) break;
            for(int i=0;i<si;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=nullptr && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right!=nullptr && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent_track[curr]!=nullptr && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* temp=q.front();
            ans.push_back(temp->val);
            q.pop();
        }
        return ans;
    }
};