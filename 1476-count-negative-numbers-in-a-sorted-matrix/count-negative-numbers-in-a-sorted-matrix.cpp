class Solution {
public:
    int search_count(vector<int> v){
        int beg=0;
    
        int end=v.size()-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(v[mid]<0) end=mid-1;
            else beg=mid+1;
        }
        return v.size()-beg;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            count+=search_count(grid[i]);
        }
        return count;
    }
};