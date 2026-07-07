class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m=s.size();
        int n=t.size();
       string a="";
       string b="";
       for(char c:s){
            if(c=='#'){
                if(!a.empty()) a.pop_back();
            }
            else{
                a+=c;
            }
        }
        for(char c:t){
            if(c=='#'){
                if(!b.empty()) b.pop_back();
            }
            else{
                b+=c;
            }
        }
        return a==b;
    }
};