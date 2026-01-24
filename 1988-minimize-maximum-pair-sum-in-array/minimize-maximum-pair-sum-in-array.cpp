class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans=max(ans,nums[i]+nums[n-i-1]);
        }
        return ans;
    }
};