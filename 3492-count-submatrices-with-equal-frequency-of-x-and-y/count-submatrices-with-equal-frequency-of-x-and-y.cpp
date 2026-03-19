class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> sum(m+1,vector<int>(n+1,0));
        vector<vector<int>> countx(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val=0;
                if(grid[i][j]=='X') val=1;
                else if(grid[i][j]=='Y') val=-1;
                int x=(grid[i][j]=='X')?1:0;
                sum[i][j]=val;
                countx[i][j]=x;
                if(i>0){
                    sum[i][j]+=sum[i-1][j];
                    countx[i][j]+=countx[i-1][j];
                }
                if(j>0){
                    sum[i][j]+=sum[i][j-1];
                    countx[i][j]+=countx[i][j-1];
                }
                if(i>0 && j>0){
                    sum[i][j]-=sum[i-1][j-1];
                    countx[i][j]-=countx[i-1][j-1];
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(sum[i][j]==0 && countx[i][j]>0) ans++;
            }
        }
        return ans;
    }
};