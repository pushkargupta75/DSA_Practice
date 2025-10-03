class Solution {
public:
    int profit(vector<int>& prices,int n,int ind,int buy,vector<vector<int>> &dp){
        int pro;
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            pro=max(-prices[ind]+profit(prices,n,ind+1,0,dp),0+profit(prices,n,ind+1,1,dp));
        }
        else{
            pro=max(prices[ind]+profit(prices,n,ind+1,1,dp),0+profit(prices,n,ind+1,0,dp));
        }
        return dp[ind][buy]=pro;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return profit(prices,n,0,1,dp);
    }
};