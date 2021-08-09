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
    
    bool solve(int row, int n, vector<string>& board, vector<vector<string> >& ans){
        if(row==n){
            ans.push_back(board);
            return false;
        }
        for(int i=0; i<n; i++){
            if(board[row][i]=='.' && isValid(row, i, n, board)){
                board[row][i]='Q';
                bool bb=  solve(row+1, n, board, ans);
                if(!bb){
                    board[row][i]='.';
                }
            }
            
        }
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string p ="";
        for(int i=0; i<n; i++)
            p+='.';
        for(int i=0; i<n; i++)
            board[i]=p;
        vector<vector<string> >ans;
        bool b  = solve(0, n, board, ans);
        return ans;
    }
};