class Solution {
public:
    int mySqrt(int x) {
        long long beg=0;
        long long end=x;
        while(beg<end){
            long long mid=beg+((end-beg+1)>>1);
            if(mid<=x/mid) beg=mid;
            else end=mid-1;
        }
        return (beg);
    }
};