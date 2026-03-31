class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int beg=0;
        int end=n-1;
        int i=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(arr[mid]==x){
                i=mid;
                break;
            }
            else if(arr[mid]<x) beg=mid+1;
            else end=mid-1;
        }
        if(i==0){
            if(beg>=n) i=n-1;
            else if(end<0) i=0;
            else if(abs(arr[beg]-x)<abs(arr[end]-x)) i=beg;
            else i=end;
        }
        vector<int> v;
        v.push_back(arr[i]);
        k--;
        int tleft=i-1;
        int tright=i+1;
        while(k>0){
            if(tleft<0) v.push_back(arr[tright++]);
            else if(tright>=n) v.push_back(arr[tleft--]);
            else if(abs(arr[tleft]-x)<=abs(arr[tright]-x)) v.push_back(arr[tleft--]);
            else v.push_back(arr[tright++]);
            k--;
        }
        sort(v.begin(),v.end());
        return v;
    }
};