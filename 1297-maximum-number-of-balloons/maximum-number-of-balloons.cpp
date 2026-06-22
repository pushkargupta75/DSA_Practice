class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        map<int,int> mp;
        for(char c:text) mp[c]++;
        return min({mp['b'],mp['a'],mp['l']/2,mp['o']/2,mp['n']});
    }
};