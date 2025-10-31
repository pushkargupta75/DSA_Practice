class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
            if(mp[i]==2) ans.push_back(i);
            if(ans.size()==2) return ans;
        }
        return ans;
    }
};