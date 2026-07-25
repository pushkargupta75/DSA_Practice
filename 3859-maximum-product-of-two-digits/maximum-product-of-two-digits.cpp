class Solution {
public:
    int maxProduct(int n) {
        int fi=0;
        int se=0;
        while(n>0){
            int t=n%10;
            if(t>fi){
                se=fi;
                fi=t;
            }
            else if(t>se) se=t;
            n/=10;
        }
        return fi*se;
    }
};