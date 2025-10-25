class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int week=0;
        while(n>0) {
            int start=week+1;
            for (int i=0;i<7 && n>0;i++) {
                ans+=start+i;
                n--;
            }
            week++;
        }
        return ans;
    }
};