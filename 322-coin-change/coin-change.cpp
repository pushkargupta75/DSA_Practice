class Solution {
public:
    // int count(vector<int>& coins,int ind,int amount,vector<vector<int>> dp){
    //     if(ind==0){
    //         if(amount%coins[ind]==0) return amount/coins[ind];
    //         else return 1e9; 
    //     }
    //     if(dp[ind][amount]!=-1) return dp[ind][amount];
    //     int not_take=0+count(coins,ind-1,amount,dp);
    //     int take=INT_MAX;
    //     if(coins[ind]<=amount) take=1+count(coins,ind,amount-coins[ind],dp);
    //     return dp[ind][amount]=min(take,not_take);
    // }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int ind=1;ind<coins.size();ind++){
            for(int j=0;j<=amount;j++){
                int not_take=0+dp[ind-1][j];
                int take=INT_MAX;
                if(coins[ind]<=j) take=1+dp[ind][j-coins[ind]];
                dp[ind][j]=min(take,not_take);
            }
        }
        int ans=dp[coins.size()-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};