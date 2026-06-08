class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans;
        for(int i:nums) if(i<pivot) ans.push_back(i);
        for(int i:nums) if(i==pivot) ans.push_back(i);
        for(int i:nums) if(i>pivot) ans.push_back(i);
        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
        return nums;
    }
};