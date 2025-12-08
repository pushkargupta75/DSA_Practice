class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int a=i*i+j*j;
                int b=sqrt(a);
                if(b<=n && b*b==a) count++;
            }
        }
        return count;
    }
};