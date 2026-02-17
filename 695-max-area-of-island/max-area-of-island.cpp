class Solution {
public: 
    void bfs(vector<vector<int>>& grid,vector<vector<int>> &vis,int row,int col,int m,int n,int &a){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        a=1;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dir[i][0];
                int ncol=col+dir[i][1];
                if(nrow>=m || ncol>=n || nrow<0 || ncol<0) continue;
                if(!vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    a++;
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int a=0;
                    bfs(grid,vis,i,j,m,n,a);
                    ans=max(ans,a);
                }
            }
        }
        return ans;
    }
};