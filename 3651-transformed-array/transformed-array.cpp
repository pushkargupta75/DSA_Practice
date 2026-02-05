class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int idx=((i+nums[i])%n+n)%n;
                ans[i]=nums[idx];
            }
            
            if(nums[i]<0){
                int idx=((i-abs(nums[i]))%n+n)%n;
                ans[i]=nums[idx];
            }
            
            if(nums[i]==0) ans[i]=nums[i];
        }
        return ans;
    }
};