class Solution {
public:
    // int count(string text1, string text2,int ind1,int ind2,vector<vector<int>> &dp){
    //     if(ind1==0 || ind2==0) return 0;
    //     if(dp[ind1-1][ind2-1]!=-1) return dp[ind1-1][ind2-1];
    //     if(text1[ind1-1]==text2[ind2-1]) return dp[ind1-1][ind2-1]=1+count(text1,text2,ind1-1,ind2-1,dp);
    //     return dp[ind1-1][ind2-1]=max(count(text1,text2,ind1-1,ind2,dp),count(text1,text2,ind1,ind2-1,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,-1));

        //base scae
        for(int i=0;i<=text1.size();i++) dp[i][0]=0;
        for(int j=0;j<=text2.size();j++) dp[0][j]=0;


        for(int ind1=1;ind1<=text1.size();ind1++){
            for(int ind2=1;ind2<=text2.size();ind2++){
                if(text1[ind1-1]==text2[ind2-1]) dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    } 
};