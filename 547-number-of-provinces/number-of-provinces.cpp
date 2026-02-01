class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int> &vis,int v){
        vis[v]=1;
        for(int it:adj[v]){
            if(!vis[it]) dfs(adj,vis,it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<isConnected[0].size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(isConnected.size(),0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt;
    }
};