class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string s="";
        long long  sum=0;
        while(n>0){
            if(n%10!=0){
                s+=to_string(n%10);
                sum+=n%10;
            }
            n/=10;
        }   
        reverse(s.begin(),s.end());
        long long num=stoll(s);
        return num*sum;
    }
};