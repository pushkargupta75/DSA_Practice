class Solution {
public:
    bool ispalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int helper(string &s,int n,vector<int> &dp,int i){
        if(i==n) return 0;
        int ans=INT_MAX;    
        if(dp[i]!=-1) return dp[i];
        
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)){
                int cost=1+helper(s,n,dp,j+1);
                ans=min(ans,cost);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return helper(s,n,dp,0)-1;
    }
};