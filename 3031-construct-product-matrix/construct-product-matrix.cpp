class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int si=m*n;
        vector<long long>prefix(si,1),suffix(si,1);
        vector<vector<int>>ans(n,vector<int>(m,1));
        for(int i=1;i<si;i++){
            int r=(i-1)/m;
            int c=(i-1)%m;
            prefix[i]=(prefix[i-1]*grid[r][c])%12345;
        }
        for(int i=si-2;i>=0;i--){
            int r=(i+1)/m;
            int c=(i+1)%m;
            suffix[i]=(suffix[i+1]*grid[r][c])%12345;
        }
        for(int i=0;i<si;i++){
            int r=i/m;
            int c=i%m;
            ans[r][c]=(prefix[i]*suffix[i])%12345;
        }
        return ans;

    }
};