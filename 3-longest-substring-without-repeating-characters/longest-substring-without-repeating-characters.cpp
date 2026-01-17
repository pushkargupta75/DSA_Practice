class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ma=0;
        int i=0;
        int j=0;
        int temp=0;
        while(j<s.size()){
            if(mp[s[j]]==0){
                mp[s[j]]++;
                temp++;
                ma=max(ma,temp);
                j++;
            }
            else{
                mp[s[i]]--;
                i++;
                temp--;

            }
        }
        return ma;
    }
};