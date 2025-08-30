class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> uniqueNums(s.begin(), s.end());  
        sort(uniqueNums.begin(), uniqueNums.end()); 
        
        int n = uniqueNums.size();
        if (n >= 3) return uniqueNums[n-3];
        return uniqueNums[n-1]; 
    }
};
