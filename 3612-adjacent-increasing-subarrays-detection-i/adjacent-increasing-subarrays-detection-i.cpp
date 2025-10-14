class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i=0;i+2*k<=n;i++) {
            bool ok1=true,ok2=true;
            for(int j=i;j<i+k-1;j++)
                if(nums[j]>=nums[j+1]) ok1=false;
            for(int j=i+k;j<i+2*k-1;j++)
                if(nums[j]>=nums[j+1]) ok2=false;

            if (ok1 && ok2) return true;
        }
        return false;
    }
};