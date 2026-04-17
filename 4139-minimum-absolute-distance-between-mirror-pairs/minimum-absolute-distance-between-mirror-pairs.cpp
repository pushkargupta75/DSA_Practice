class Solution {
public:
    int rev(int n){
        int ans=0;
        while(n>0){
            ans=ans*10+(n%10);
            n/=10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()) ans=min(ans,i-mp[nums[i]]);
            mp[rev(nums[i])]=i;
        }
        return (ans==INT_MAX)?-1:ans;
    }
};