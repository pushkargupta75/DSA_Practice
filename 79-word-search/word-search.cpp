class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    bool find(int i,int j,vector<vector<char>>& board,int idx,string word){
        if(idx==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='@') return false;
        if(board[i][j]!=word[idx]) return false;
        char temp=board[i][j];
        board[i][j]='@';
        for(int k=0;k<4;k++){
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            if(find(ni,nj,board,idx+1,word)) return true;
        }
        board[i][j]=temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && find(i,j,board,0,word)) return true;
            }
        }
        return false;
    }
};