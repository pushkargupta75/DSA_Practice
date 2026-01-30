class Solution {
public: 
    bool helper(long long mid,vector<int>& time, int totalTrips){
        long long total=0;
        for(int i=0;i<time.size();i++){
            total+=1ll*floor(mid/time[i]);
            if(total>=totalTrips) return true;
        }
        return total>=totalTrips;

    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0;
        long long r=LONG_MAX;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(helper(mid,time,totalTrips)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }   
};