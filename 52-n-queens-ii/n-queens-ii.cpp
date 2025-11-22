class Solution {
public:
    bool is_safe(int row,int col,vector<string> &board,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(board[row--][col--]=='Q') return false;
        }
        col=dupcol;
        row=duprow;
        while(col>=0){
            if(board[row][col--]=='Q') return false;
        }
        col=dupcol;
        row=duprow;
        while(row<n && col>=0){
            if(board[row++][col--]=='Q') return false;
        }
        return true; 
    
    }
    void solve(int col,vector<string> &board,int n,int &count){
        if(col==n){
            
            count++;
            return;
        }
        for(int row=0;row<n;row++){
            if(is_safe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,n,count);
                board[row][col]='.';

            }
            
        }
        

    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int count = 0;
        solve(0, board, n, count);
        return count;
    }
};