class Solution {
public:
    void left_shift(vector<vector<int>>&temp,int i){
        int t=temp[i][0];
        for(int j=0;j<temp[i].size()-1;j++){
            temp[i][j]=temp[i][j+1];
        }
        temp[i][temp[i].size()-1]=t;
    }
    void right_shift(vector<vector<int>>&temp,int i){
        int t=temp[i][temp[i].size()-1];
        for(int j=temp[i].size()-1;j>0;j--){
            temp[i][j]=temp[i][j-1];
        }
        temp[i][0]=t;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> temp=mat;
        k=k%n;
        for(int l=0;l<k;l++){
            for(int i=0;i<m;i++){
                if(i%2==0){
                    left_shift(temp,i);
                }
                else right_shift(temp,i);
            }
        }
        if(mat==temp) return true;
        return false;
    }
};