class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0;
        int temp=0;
        for(int i=0;i<gain.size();i++){
            temp+=gain[i];
            alt=max(alt,temp);
        }
        return alt;
    }
};