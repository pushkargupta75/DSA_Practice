class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = 0, sumBob = 0;
        for (int x:aliceSizes) sumAlice += x;
        for (int x:bobSizes) sumBob += x;
        for (int x:aliceSizes) {
            for (int y:bobSizes) {
                if (sumAlice-x+y==sumBob-y+x) {
                    return {x,y};
                }
            }
        }
        return {};
    }
};