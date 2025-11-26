class Solution {
public:
    int helper(string word1, string word2,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(word1[ind1]==word2[ind2]) return dp[ind1][ind2]=1+helper(word1,word2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=max(helper(word1,word2,ind1-1,ind2,dp),helper(word1,word2,ind1,ind2-1,dp));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n,-1));
        int t=helper(word1,word2,m-1,n-1,dp);
        return m+n-2*t;
    }
};