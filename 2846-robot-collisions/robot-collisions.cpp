class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<tuple<int,int,char,int>> robots;
        for(int i=0;i<n;i++) robots.push_back({positions[i],healths[i],directions[i],i});
        sort(robots.begin(),robots.end());
        stack<int> st;
        for(int i=0;i<n;i++){
            auto&[pos,heal,dir,idx]=robots[i];
            if(dir=='R') st.push(i);
            else{
                while(!st.empty()){
                    int to=st.top();
                    auto&[pos2,heal2,dir2,idx2]=robots[to];
                    if(heal2<heal){
                        heal--;
                        st.pop();
                        heal2=0;
                    }
                    else if(heal<heal2){
                        heal2--;
                        heal=0;
                        break;
                    }
                    else{
                        heal2=0;
                        heal=0;
                        st.pop();
                        break;
                    }
                }
            }
        }
        vector<pair<int,int>> res;
        vector<int> ans;
        for(auto &[a,b,c,d]:robots){
            if(b>0) res.push_back({d,b});
        }
        sort(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            ans.push_back(res[i].second);
        }
        return ans;
    }
};