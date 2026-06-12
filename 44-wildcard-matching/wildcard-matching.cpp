class Solution {
public:
    // bool helper(string s,string p,int i,int j){
    //     if(i==s.size() && j==p.size()) return true;
    //     if(j==p.size()) return false;
    //     if(i==s.size()){
    //         while(j<p.size()){
    //             if(p[j]!='*') return false;
    //             j++;
    //         }
    //         return true;
    //     }
    //     if(s[i]==p[j] || p[j]=='?') return helper(s,p,i+1,j+1);
    //     if(p[j]=='*') return helper(s,p,i+1,j) || helper(s,p,i,j+1);
    //     return false;
    // }
    bool isMatch(string s, string p) {
        // return helper(s,p,0,0);
        int i=0;
        int j=0;
        int star=-1;
        int match=0;
        while(i<s.size()){
            if(j<p.size() &&(s[i]==p[j] || p[j]=='?')){
                i++;
                j++;
            }
            else if(j<p.size() & p[j]=='*'){
                star=j;
                match=i;
                j++;
            }
            else if(star!=-1){
                j=star+1;
                match++;
                i=match;
            }
            else return false;
        }
        while(j<p.size() && p[j]=='*') j++;
        return j==p.size();
    }
};