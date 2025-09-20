// class Solution {
// public:
//     double myPow(double x, long n) {
//         double t=1;
//         if(x==1) return 1;
//         if(n==1) t=x;
//         else if(n>0) for(long i=0;i<n;i++) t*=x;
//         else if(n<0) for(long i=0;i<n*(-1);i++) t=t/x;
//         return t;
    
//     }
// };

class Solution {
 public:
  double myPow(double x, long n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / myPow(x, -n);
    if (n % 2 == 1) return x * myPow(x, n - 1);
    return myPow(x * x, n / 2);
  }
};