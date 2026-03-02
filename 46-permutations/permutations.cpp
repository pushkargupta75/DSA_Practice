class Solution {
public:
    void helper(vector<int>& nums,vector<int> temp,vector<vector<int>> &ans,vector<int> used){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(used[j]==0){
                used[j]=1;
                temp.push_back(nums[j]);
                helper(nums,temp,ans,used);
                temp.pop_back();
                used[j]=0;
            }
        
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        vector<int> used(nums.size(),0);
        helper(nums,temp,ans,used);
        return ans;
    }
};