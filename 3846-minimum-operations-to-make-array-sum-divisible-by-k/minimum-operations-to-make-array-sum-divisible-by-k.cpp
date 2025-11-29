class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        int count=0;
        if(sum%k==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int t=sum%k;
            for(int j=0;j<t;j++){
                if(nums[i]==0) break;
                    nums[i]-=1;
                    sum-=1;
                    count++;
                if(sum%k==0) return count;
            }
        }
        return count;
    }
};