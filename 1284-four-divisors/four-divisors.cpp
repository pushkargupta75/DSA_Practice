class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int a=0;
        for(int i=0;i<nums.size();i++){
            int count=0;
            vector<int> ans;
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    ans.push_back(j);
                    count++;
                    if(j!=nums[i]/j){
                        ans.push_back(nums[i]/j);
                        count++;
                    }
                }
                if(count>2) break;
            }
            if(count==2) a+=1+nums[i]+ans[0]+ans[1];
        }
        return a;
    }
};