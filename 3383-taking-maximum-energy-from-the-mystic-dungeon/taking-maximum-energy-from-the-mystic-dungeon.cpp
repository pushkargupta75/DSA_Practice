class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ma=INT_MIN;
        int n=energy.size();
        vector<int> dp(n, 0);
        for(int i=n-1;i>=0;i--){
            if(i+k<n) dp[i]=dp[i+k]+energy[i];
            else dp[i]=energy[i];
            ma=max(ma,dp[i]);
        }
        return ma;
    }
};