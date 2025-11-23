class Solution {
public:
    // int helper(vector<int>& nums,int ind,int sum,vector<vector<int>>& dp){
    //     if(ind==nums.size()){
    //         if(sum%3==0) return sum;
    //         else return 0;
    //     }
    //     if(dp[ind][sum]!=-1) return dp[ind][sum];
    //     int pick=helper(nums,ind+1,sum+nums[ind],dp);
    //     int notpick=helper(nums,ind+1,sum,dp);
    //     return dp[ind][sum]=max(pick,notpick);
    // }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        // int total=0;
        // for(int i=0;i<n;i++) total+=nums[i];
        vector<int> dp(3,0);
        for(int num:nums) {
            vector<int>temp=dp;
            for(int i=0;i<3;i++) {
                int newMod=(temp[i]+num)%3;
                dp[newMod]=max(dp[newMod],temp[i]+num);
            }
        }
        return dp[0];
    }
};