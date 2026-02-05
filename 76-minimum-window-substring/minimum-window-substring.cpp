class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int i=0,j=0,cnt=0;
        int stidx=-1;
        int minlen=INT_MAX;

        for(int i=0;i<t.size();i++) mp[t[i]]++;

        while(j<s.size()){
            if(mp[s[j]]>0) cnt++;

            mp[s[j]]--;

            while(cnt==t.size()){
                if(j-i+1<minlen){
                    minlen=j-i+1;
                    stidx=i;
                }
            
                mp[s[i]]++;
                if(mp[s[i]]>0) cnt--;
                i++;
            }
            
            j++;
        }
        return stidx==-1?"":s.substr(stidx,minlen);
    }
};