class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for(string c:operations){
            if(c=="+") ans.push_back(ans.back()+ans[ans.size() - 2]);
            else if(c=="D") ans.push_back(ans.back()*2);
            else if(c=="C") ans.pop_back();
            else ans.push_back(stoi(c));
        }
        int an=0;
        for(int i=0;i<ans.size();i++){
            an+=ans[i];
        }
        return an;
    }
};