class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=n;
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(j<i) j=i;
            while(j<n && nums[j]<=1LL*k*nums[i]) j++;
            ans=min(ans,n-(j-i));
            
        }
        return ans;
    }
};