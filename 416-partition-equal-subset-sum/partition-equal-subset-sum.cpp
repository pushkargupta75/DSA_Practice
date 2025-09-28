class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int n:nums) total+=n;

        if (total%2!=0) return false;
        int target=total/2;
        vector<bool> dp(target+1,false);
        dp[0]=true;
        for(int num:nums) {
            for(int i=target;i>=num;i--) {
                if(dp[i-num]) dp[i]=true;
            }
        }
        return dp[target];
        
    }
};