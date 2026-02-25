class Solution {
public:
    int countbits(int n){
        int cnt=0;
        while(n>1){
            cnt+=n&1;
            n=n>>1;
        }
        if(n==1) cnt++;
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++){
            v.push_back({countbits(arr[i]),arr[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<arr.size();i++){
            arr[i]=v[i].second;
        }
        return arr;
    }
};