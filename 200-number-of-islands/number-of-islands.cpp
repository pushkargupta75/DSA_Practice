class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>> &vis,int row,int col,int m,int n){
        vis[row][col]=1;

        queue<pair<int,int>> q;
        
        q.push({row,col});
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
        
            for(int k=0;k<4;k++){
                int nrow=row+drow[k];
                int ncol=col+dcol[k];
                    
        
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1' && !vis[nrow][ncol]  ){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(grid,vis,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};