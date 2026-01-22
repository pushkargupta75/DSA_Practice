class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i=0;
        int count=0;
        for(int j=0;j<costs.size();j++){
            if(coins>=costs[j]){
                count++;
                coins-=costs[j];   
            }
        }
        return count;
    }
};