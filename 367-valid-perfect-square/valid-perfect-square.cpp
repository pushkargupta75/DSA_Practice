class Solution {
public:
    bool isPerfectSquare(int num) {
        long long beg=0;
        long long end=num;
        while(beg<=end){
            long long mid=beg+(end-beg)/2;
            if(mid*mid==num) return true;
            else if(mid*mid<num) beg=mid+1;
            else end=mid-1;
        }
        return false;
    }
};