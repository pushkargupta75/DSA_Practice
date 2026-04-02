// class Solution {
// public:
//     int helper(vector<vector<int>>& coins,int k,int i,int j,vector<vector<vector<int>>>&dp,int m,int n){
//         if(i>=m || j>=n) return INT_MIN ;
//         if(i==m-1 && j==n-1){
//             if(coins[i][j]<0){
//                 if(k>0) return max(0,coins[i][j]);
//             }
//             return dp[i][j][k]=coins[i][j];
//         }
//         if(dp[i][j][k]!=-1) return dp[i][j][k];
//         int down=helper(coins,k,i,j+1,dp,m,n);
//         int right=helper(coins,k,i+1,j,dp,m,n);
        
        
//         int ans=INT_MIN;
        
//         if(coins[i][j]>=0){
            
//             if(down != INT_MIN) ans = max(ans, coins[i][j] + down);
//             if(right != INT_MIN) ans = max(ans, coins[i][j] + right);
//         }
//         else{
//             if(down != INT_MIN) ans = max(ans, coins[i][j] + down);
//             if(right != INT_MIN) ans = max(ans, coins[i][j] + right);
//             if(k>0){    
//                 int right2=helper(coins,k-1,i+1,j,dp,m,n);
//                 int down2=helper(coins,k-1,i,j+1,dp,m,n);
//                 int n_k=max(right2,down2);
//                 if(n_k!=INT_MIN) ans=max(ans,n_k);
//             }
//         }
//         return dp[i][j][k]=ans;

//     }
//     int maximumAmount(vector<vector<int>>& coins) {
//         int m=coins.size();
//         int n=coins[0].size();
//         vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,-1)));
//         return helper(coins,2,0,0,dp,m,n);
//     }
// };

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3, INT_MIN)));
        for(int k=0;k<=2;k++){
            if(coins[m-1][n-1]<0 && k>0) dp[m-1][n-1][k]=0;
            else dp[m-1][n-1][k]=coins[m-1][n-1];
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                for(int k=0;k<=2;k++){
                    int ans = INT_MIN;
                    if(j+1<n){
                        if(coins[i][j] >= 0){
                            if(dp[i][j+1][k]!=INT_MIN) ans=max(ans,coins[i][j]+dp[i][j+1][k]);
                        } else {
                            if(dp[i][j+1][k]!=INT_MIN) ans=max(ans,coins[i][j]+dp[i][j+1][k]);
                            if(k>0 && dp[i][j+1][k-1]!=INT_MIN) ans=max(ans,dp[i][j+1][k-1]);
                        }
                    }
                    if(i+1<m){
                        if(coins[i][j] >= 0){
                            if(dp[i+1][j][k]!=INT_MIN) ans=max(ans,coins[i][j]+dp[i+1][j][k]);
                        } else {
                            if(dp[i+1][j][k]!=INT_MIN) ans=max(ans,coins[i][j]+dp[i+1][j][k]);
                            if(k > 0 && dp[i+1][j][k-1]!=INT_MIN) ans=max(ans,dp[i+1][j][k-1]);
                        }
                    }
                    dp[i][j][k]=ans;
                }
            }
        }
        return dp[0][0][2];
    }
};