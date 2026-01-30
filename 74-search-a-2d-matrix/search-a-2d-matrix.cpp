class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            int beg=0;
            int end=n-1;
            while(beg<=end){
                int mid=beg+(end-beg)/2;
                if(matrix[i][end]<target) break;
                if(matrix[i][mid]==target) return true;
                if(matrix[i][mid]<target) beg=mid+1;
                else end=mid-1;
            }
        }
        return false;

    }
};