class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ma=INT_MIN;
        int i=0;
        int j=n-1;
        while(colors[i]==colors[j]) j--;
        ma=max(ma,abs(i-j));
        j=n-1;
        while(colors[i]==colors[j]) i++;
        ma=max(ma,abs(i-j));
        return ma;
    }
};