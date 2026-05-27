class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        string s="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int count=0;
        for(int i=0;i<26;i++){
            if(word.find(s[i])!=string::npos && word.find(s[i+26])!=string::npos){
                int fi=word.rfind(s[i]);
                int la=word.find(s[i+26]);
                if(fi<la) count++;
            }
        }
        return count;
    }
};