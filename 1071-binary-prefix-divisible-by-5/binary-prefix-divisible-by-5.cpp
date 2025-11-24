class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size(),false);
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp=(temp*2+nums[i])%5;
            if(temp%5==0) ans[i]=true;
        }
        return ans;
    }
};