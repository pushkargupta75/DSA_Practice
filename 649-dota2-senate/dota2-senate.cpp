class Solution {
public:
    void remove_s(string senate,vector<bool> &removed,char ch,int idx){
        while(true){
            if(senate[idx]==ch && removed[idx]==false){
                removed[idx]=true;
                break;
            }
             idx=(idx+1)%senate.size();
        }
    }
    string predictPartyVictory(string senate) {
        int n=senate.size();
        int r_count=count(senate.begin(),senate.end(),'R');
        int d_count=count(senate.begin(),senate.end(),'D');
        int idx=0;
        vector<bool> removed(n,false);
        while(r_count>0 && d_count>0){
            if(removed[idx]==false){
                if(senate[idx]=='R'){
                    remove_s(senate,removed,'D',(idx+1)%senate.size());
                    d_count--;
                }
                else{
                    remove_s(senate,removed,'R',(idx+1)%senate.size());
                    r_count--;
                }
            }
            idx=(idx+1)%senate.size();
        }
        return r_count==0? "Dire":"Radiant";
        
    }
};