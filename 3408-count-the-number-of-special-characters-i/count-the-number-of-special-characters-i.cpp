class Solution {
public:
    int numberOfSpecialChars(string word) {
        string s="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int count=0;
        for(int i=0;i<26;i++){
            if(word.find(s[i])!=string::npos && word.find(s[i+26])!=string::npos) count++;
            
        }
        return count;
    }
};