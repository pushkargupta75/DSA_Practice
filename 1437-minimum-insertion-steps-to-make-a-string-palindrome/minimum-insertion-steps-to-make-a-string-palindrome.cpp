class Solution {
public:
    int helper(string word1, string word2,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(word1[ind1]==word2[ind2]) return dp[ind1][ind2]=1+helper(word1,word2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=max(helper(word1,word2,ind1-1,ind2,dp),helper(word1,word2,ind1,ind2-1,dp));
    }
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        
        int n=s.size();
        vector<int> dp(n+1,0),prev(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]) dp[j]=1+prev[j-1];
                else dp[j]=max(prev[j],dp[j-1]);
            }
            prev=dp;
        }

        return n-dp[n];

    }
};