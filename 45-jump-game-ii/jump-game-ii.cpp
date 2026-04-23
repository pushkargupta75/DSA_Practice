class Solution {
public:
    int helper(int i,vector<int>& nums,vector<int> &dp,int n){
        if(i>=n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int far=min(i+nums[i],n-1);
        int ans=INT_MAX;
        for(int idx=i+1;idx<=far;idx++){
            int res=helper(idx,nums,dp,n);
            if(res!=INT_MAX) ans=min(ans,1+res);
        }
        return dp[i]=ans;
        
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return helper(0,nums,dp,n);
    }
};