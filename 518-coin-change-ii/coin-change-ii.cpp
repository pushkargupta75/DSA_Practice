class Solution {
public:
    int count(int ind,int amount, vector<int>& coins,vector<vector<int>> &dp){
       if(ind==0){
            if(amount%coins[ind]==0) return 1;
            else return 0; 
        }   
        if(dp[ind][amount]!=-1) return dp[ind][amount]; 
        int not_take=count(ind-1,amount,coins,dp);
        int take=0;
        if(coins[ind]<=amount) take=count(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        return count(coins.size()-1,amount,coins,dp);
    }
};