class Solution {
public:
    bool dfs(int v,int col,vector<int> &color, vector<vector<int>>&graph){
        color[v]=col;
        for(int it:graph[v]){
            if(color[it]==-1){
                if(!dfs(it,!col,color,graph)) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false) return false;
            }
        }
        return true;
    }
};