class Solution {
public:
    int profit(vector<int>& prices,int n,int ind,int buy,int cap,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(ind==n) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap]=max(-prices[ind]+profit(prices,n,ind+1,0,cap,dp),0+profit(prices,n,ind+1,1,cap,dp));
        }
        else{
            return dp[ind][buy][cap]=max(prices[ind]+profit(prices,n,ind+1,1,cap-1,dp),0+profit(prices,n,ind+1,0,cap,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));


        //base case
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                dp[n][buy][cap]=0;
            }
        }
        for(int ind=0;ind<n;ind++){
            for(int buy=0;buy<=1;buy++){
                dp[ind][buy][0]=0;
            }
        }


        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                    }
                    else{
                        dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};