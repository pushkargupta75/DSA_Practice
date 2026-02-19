class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        sort(stones.begin(),stones.end());
        for(int i=n-1;i>0;i--){
            int a=stones[i];
            int b=stones[i-1];
            stones.pop_back();
            stones.pop_back();
            stones.push_back(abs(a-b));
            sort(stones.begin(),stones.end());
        }
        return stones[0];
    }
};