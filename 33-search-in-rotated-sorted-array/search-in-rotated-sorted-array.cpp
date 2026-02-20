class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg=0;
        int end=nums.size()-1;
        int ans=-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;

            if(nums[mid]==target) return mid;

            if(nums[beg]<=nums[mid]){
                if(nums[beg]<=target && nums[mid]>target) end=mid-1;
                else beg=mid+1;
            }

            else{
                if(target<=nums[end] && nums[mid]<target) beg=mid+1;
                else end=mid-1;
            }
            
        }
        return ans;
    }
};