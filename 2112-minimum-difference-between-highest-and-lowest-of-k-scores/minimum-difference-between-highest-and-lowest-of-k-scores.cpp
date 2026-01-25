class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0;
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i+k-1<nums.size();i++){
            int j=i+k-1;
            ans=min(ans,nums[j]-nums[i]);
        }
        return ans;
    }
};