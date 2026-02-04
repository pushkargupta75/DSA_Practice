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
    TreeNode* markparent(TreeNode* root, int start,unordered_map<TreeNode*,TreeNode*>& parent_track){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startnode=nullptr;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start){
                startnode=node;
            }

            if(node->left){
                parent_track[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent_track[node->right]=node;
                q.push(node->right);
            }
        }
        return startnode;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        TreeNode* startnode=markparent(root,start,parent_track);

        int mins=0;
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;

        q.push(startnode);
        visited[startnode]=true;
        int cur_level=0;
        
        while(!q.empty()){
            int si=q.size();
            bool infected=false;
            for(int i=0;i<si;i++){
                TreeNode* cur=q.front();
                q.pop();
                
                if(cur->left!=nullptr && !visited[cur->left]){
                    q.push(cur->left);
                    visited[cur->left]=true;
                    infected=true;
                }
                if(cur->right!=nullptr && !visited[cur->right]){
                    q.push(cur->right);
                    visited[cur->right]=true;
                    infected=true;
                }
                if(parent_track[cur]!=nullptr && !visited[parent_track[cur]]){
                    q.push(parent_track[cur]);
                    visited[parent_track[cur]]=true;
                    infected=true;
                }
            }
            if(infected) mins++;
        }
        return mins;

    }
};