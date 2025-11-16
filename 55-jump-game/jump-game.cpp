class Solution {
public:
    bool helper(vector<int>& nums,int ind,vector<int>&dp){
        if (ind>=nums.size()-1) return true;
        if(dp[ind]!=-1) return dp[ind];
        int far=min(ind+nums[ind],(int)nums.size()-1);
        for(int next=ind+1;next<=far;next++){
            if(helper(nums,next,dp)){
                dp[ind]=1;
                return true;
                
            } 
        }
        dp[ind]=0;
        return false;

    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};