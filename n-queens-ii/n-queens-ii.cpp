class Solution {
public:
     bool isValid(int row, int col, int n, vector<string>& board){
        //check up
        for(int i=row-1; i>=0; i--){
            if(board[i][col]=='Q')
                return false;
        }
        //check left diagonal 
        int l= row-1;
        int r= col-1;
        while(l>=0 && r>=0){
            if(board[l][r]=='Q')
                return false;
            l--;
            r--;
        }
        //check right diagonal
        l=row-1;
        r =col+1;
        while(l>=0 && r<n){
            if(board[l][r]=='Q')
                return false;
            l--;
            r++;
        }
        return true;
        
    }
    int cnt;
    bool solve(int row, int n, vector<string>& board){
        if(row==n){
            cnt++;
            return false;
        }
        for(int i=0; i<n; i++){
            if(board[row][i]=='.' && isValid(row, i, n, board)){
                board[row][i]='Q';
                bool bb=  solve(row+1, n, board);
                if(!bb){
                    board[row][i]='.';
                }
            }
            
        }
        return false;
    }
    int totalNQueens(int n) {
         vector<string>board(n);
        string p ="";
        for(int i=0; i<n; i++)
            p+='.';
        for(int i=0; i<n; i++)
            board[i]=p;
        
        bool b  = solve(0, n, board);
        return cnt;
    }
};