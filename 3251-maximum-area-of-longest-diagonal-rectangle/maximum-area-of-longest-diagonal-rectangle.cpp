class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int an=INT_MIN;
        float ans=-1;
        float t;
        for(int i=0;i<dimensions.size();i++){
            t=sqrt(pow(dimensions[i][0],2)+pow(dimensions[i][1],2));
            if (ans < t || (ans == t && dimensions[i][0]*dimensions[i][1]>dimensions[an][0]*dimensions[an][1])){
            ans=t;
            an=i;
            }
        }
        return dimensions[an][0]*dimensions[an][1];
    }
};