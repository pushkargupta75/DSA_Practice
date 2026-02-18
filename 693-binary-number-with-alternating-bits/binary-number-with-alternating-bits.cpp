class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag=n%2;
        while(n!=0){
            n=n>>1;
            if(n==0) break;
            if((n%2)==flag) return false;
            flag=n%2;
        }
        return true;
    }
};