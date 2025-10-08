class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        int m=potions.size();
        for(int &spell:spells){
            long long required=(success+spell-1)/spell;
            int idx=lower_bound(potions.begin(),potions
            .end(),required)-potions.begin();
            ans.push_back(m-idx);
        }
        return ans;

    }   
};