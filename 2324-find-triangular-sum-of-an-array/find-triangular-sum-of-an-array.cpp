
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()>1){
            vector<int> newnums;
            for(int i=0;i<nums.size()-1;i++){
            newnums.push_back((nums[i]+nums[i+1])%10);
            }
            nums=newnums;
        }
        return nums[0];
    }
};