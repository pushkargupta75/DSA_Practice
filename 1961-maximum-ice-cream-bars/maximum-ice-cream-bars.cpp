class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        int count=0;
        for(int i:costs){
            if(coins!=0 && i<=coins){
                ans+=i;
                count++;
                coins-=i;
            }
        }
        return count;
    }
};