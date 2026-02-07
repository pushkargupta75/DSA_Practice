class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        if(n==0) return 0;
        vector<int>prefix(n,0);
        vector<int> suffix(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='b') prefix[i]=(i>0?prefix[i-1]:0)+1;
            else prefix[i]=(i>0?prefix[i-1]:0);
        }
        for(int i=n-1;i>=0;i--){
            suffix[i] = (i==n-1 ? 0 : suffix[i+1]);
            if(s[i]=='a') suffix[i]++;
        }
   
        int ans=n;
        ans=min(ans,suffix[0]);
        ans=min(ans,prefix[n-1]);
        for(int i=1;i<n;i++) ans=min(ans,prefix[i-1]+suffix[i]);
        return ans;
    }
};