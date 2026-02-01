class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int f=nums[0];
        int s=INT_MAX;
        int t=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<s){
                t=s;
                s=nums[i];
            }
            else if(nums[i]<t) t=nums[i];
        }
        return f+s+t;
    }
};