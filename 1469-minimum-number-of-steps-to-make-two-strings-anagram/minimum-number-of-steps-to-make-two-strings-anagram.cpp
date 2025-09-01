class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for (char c : s) mp1[c]++;
        for (char c : t) mp2[c]++;
        for(auto &p : mp1){
            char ch = p.first;
            if(mp1[ch] > mp2[ch]) ans += (mp1[ch] - mp2[ch]);
        }
        return ans;
    }
};