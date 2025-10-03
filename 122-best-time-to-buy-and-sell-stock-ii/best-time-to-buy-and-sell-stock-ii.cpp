class Solution {
public:
    // int profit(vector<int>& prices,int n,int ind,int buy,vector<vector<int>> &dp){
    //     int pro;
    //     if(ind==n) return 0;
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     if(buy){
    //         pro=max(-prices[ind]+profit(prices,n,ind+1,0,dp),0+profit(prices,n,ind+1,1,dp));
    //     }
    //     else{
    //         pro=max(prices[ind]+profit(prices,n,ind+1,1,dp),0+profit(prices,n,ind+1,0,dp));
    //     }
    //     return dp[ind][buy]=pro;
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                    int pro=0;
                    if(buy){
                        pro=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                    }
                    else{
                        pro=max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
                    }
                    dp[ind][buy]=pro;
            }
        }




        return dp[0][1];
    }
};