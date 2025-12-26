class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> count_N(customers.size()+1,0);
        vector<int> count_Y(customers.size()+1,0);
        int ans=INT_MAX;
        int idx=0;
        for(int i=0;i<customers.size();i++){
            count_N[i+1]=count_N[i];
            if(customers[i]=='N'){
                count_N[i+1]++;
            }
        }
        for(int i=customers.size()-1;i>=0;i--){
            count_Y[i]=count_Y[i+1];
            if(customers[i]=='Y'){
                count_Y[i]++;
            }
        }
        
        for(int i=0;i<=customers.size();i++){
            if(ans>count_N[i]+count_Y[i]){
                ans=count_N[i]+count_Y[i];
                idx=i;
            } 
        }
        return idx;
    }
};