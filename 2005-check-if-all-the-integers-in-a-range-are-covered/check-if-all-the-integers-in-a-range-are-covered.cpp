class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool covered[51] = {false};
        for (int i=0;i<ranges.size();i++){
            int start = ranges[i][0], end = ranges[i][1];
            for (int j = start; j <= end; j++) {
                if (j >= 1 && j <= 50)
                    covered[j] = true;
            }
        }
        for (int i = left; i <= right; i++) {
            if (!covered[i]) return false;
        }
        return true;
    }
};