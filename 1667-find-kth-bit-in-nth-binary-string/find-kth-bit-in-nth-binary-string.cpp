class Solution {
public:
    string reverse(string s){
        string temp="";
        for(int i=s.size()-1;i>=0;i--){
            temp+=s[i];
        }
        return temp;
    }
    string invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') s[i]='0';
            else s[i]='1'; 
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n;i++){
            string prev=s;
            s=prev+"1"+reverse(invert(prev));
        }
        return s[k-1];
    }
};