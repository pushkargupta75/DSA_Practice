class Solution {
public:
    bool check_anagrams(string s1,string s2){
        if (s1.size()!=s2.size()) return false;
        vector<int> freq(26,0);
        for(char c:s1) freq[c-'a']++;
        for(char c:s2) freq[c-'a']--;
       for (int count:freq)
            if(count!=0) return false;

        return true;

    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        if(words.empty()) return ans;

        ans.push_back(words[0]);
        for (int i=1;i<words.size();i++) {
            if (!check_anagrams(words[i],words[i - 1])) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};