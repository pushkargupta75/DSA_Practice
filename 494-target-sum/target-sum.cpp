class Solution {
public:
    int helper(vector<int>& nums,int sum,int i,vector<vector<int>>&dp,int n,int target,int offset){
        if(i==n){
            return (sum==target)?1:0;
        }
        if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];
        int sub=helper(nums,sum+nums[i],i+1,dp,n,target,offset);
        int add=helper(nums,sum-nums[i],i+1,dp,n,target,offset);
        return dp[i][sum+offset]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        int total=0;
        for(int x:nums) total+=x;
        int offset=total;
        vector<vector<int>> dp(n,vector<int>(2*total+1,-1));
        return helper(nums,0,0,dp,n,target,offset);
    }
};