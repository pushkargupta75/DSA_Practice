class Solution {
public:
    void helper(int i,vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || i>=candidates.size()) return;
        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            if(candidates[j]>target) break;
            temp.push_back(candidates[j]);
            helper(j+1,candidates,target-candidates[j],ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target,ans,temp);
        return ans;
    }
};