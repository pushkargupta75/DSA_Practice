class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;
        unordered_map<char,int> mp2;
        for(auto c:s) {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') mp[c]++;
            else mp2[c]++;
        }
        int ma=0;
        int ma2=0;
        for(const auto& pair : mp) ma=max(ma,pair.second);
        for(const auto& pair : mp2) ma2=max(ma2,pair.second);
        return ma+ma2;

    }
};