class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int count=0;
        unordered_map<int,int> mp;
        int ma=INT_MIN;
        for(int num:nums) mp[num]++;
        for(auto i:mp) ma=max(ma,i.second);
        for(auto i:mp) if(ma==i.second) count++;
        return count*ma;
    }
};