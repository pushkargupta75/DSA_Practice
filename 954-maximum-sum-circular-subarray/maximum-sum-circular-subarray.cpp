class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int minsum=INT_MAX;
        int maxsum=INT_MIN;
        int curmax=0;
        int curmin=0;
        int total=0;
        for(int i=0;i<n;i++){
            int x=nums[i];

            curmax+=x;
            maxsum=max(maxsum,curmax);
            if(curmax<0) curmax=0;

            curmin+=x;
            minsum=min(minsum,curmin);
            if(curmin>0) curmin=0;

            total+=x;
            
        }
        if(maxsum<0) return maxsum;
        return max(maxsum,total-minsum);
    }
};