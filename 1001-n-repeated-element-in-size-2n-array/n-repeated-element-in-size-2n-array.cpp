class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> mp;
        for(int i:nums) mp[i]++;
        for(auto i:mp) if(i.second==n/2) ans=i.first;
        return ans;
    }
};