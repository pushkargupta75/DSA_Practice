class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices%2!=0) return {};
        int jumbo=(tomatoSlices-2*cheeseSlices)/2;
        int small=(4*cheeseSlices-tomatoSlices)/2;
        if(jumbo<0 || small <0) return {};
        return {jumbo,small};
    }
};