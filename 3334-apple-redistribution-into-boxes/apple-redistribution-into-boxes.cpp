class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int count=0;
        int total=0;
        sort(capacity.begin(),capacity.end(),greater<int>());
        for(int x:apple) total+=x;
        for(int i:capacity){
            total-=i;
            count++;
            if(total<=0) break;
        }
        return count;
    }
};