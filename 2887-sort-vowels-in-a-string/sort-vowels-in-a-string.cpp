class Solution {
public:
    string sortVowels(string s) {
        string ans="";
        vector<char> temp;
        for(auto c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                temp.push_back(c);
            }
        }
        sort(temp.begin(),temp.end());
        int i=0;
        for(auto c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                ans+=temp[i++];
            }
            else ans+=c;
        }
        return ans;
    }   
};