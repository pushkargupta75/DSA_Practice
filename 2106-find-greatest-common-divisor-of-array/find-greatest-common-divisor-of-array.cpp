class Solution {
public:
    int gcd(int a,int b){
        int mi=min(a,b);
        int ans=1;
        for(int i=1;i<=mi;i++){
            if(a%i==0 && b%i==0) ans=i;
        }
        return ans;
    }
    int findGCD(vector<int>& nums) {
        return gcd(*max_element(nums.begin(),nums.end()),*min_element(nums.begin(),nums.end()));
    }
};