class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& mat,int m){
        vector<vector<int>> temp(m,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                temp[m-j-1][i]=mat[i][j];
            }
        }
        return temp;
    }
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(mat[i][j]!=target[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m=mat.size();
        vector<vector<int>>temp=mat;
        for(int i=0;i<4;i++){
            if(check(temp,target)) return true;
            temp=rotate(temp,m);
        }
        return false;
        
    }
};