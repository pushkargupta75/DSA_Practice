class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    // int i = 0;

    // for (const int num : nums)
    //   if (i < 1 || num > nums[i - 1])
    //     nums[i++] = num;

    // return i;


    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]) {
        nums.erase(nums.begin()+i);
        i--;
        }
    }
    return nums.size();






  }
};