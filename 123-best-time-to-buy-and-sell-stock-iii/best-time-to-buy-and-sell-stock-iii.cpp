class Solution {
public:
    int profit(vector<int>& prices,int n,int ind,int buy,int cap,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(ind==n) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap]=max(-prices[ind]+profit(prices,n,ind+1,0,cap,dp),profit(prices,n,ind+1,1,cap,dp));
        }
        else{
            return dp[ind][buy][cap]=max(prices[ind]+profit(prices,n,ind+1,1,cap-1,dp),profit(prices,n,ind+1,0,cap,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
        return profit(prices,n,0,1,2,dp);
    }
};