class Solution {
public:
    int helper(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int i=0,j=0,count=0;
        int temp=0;
        while(j<nums.size()){
            temp+=nums[j];
            while(temp>goal){
                temp-=nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return helper(nums,goal)-helper(nums,goal-1);
    }
};