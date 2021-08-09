class Solution {
public:
    bool chkRow(int row, char c, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[row][i]==c)
                return false;
        }
        return true;
    }
    bool chkCol(int col, char c, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[i][col]==c)
                return false;
        }
        return true;
    }
    bool chkBox(int row, int col, char c, vector<vector<char>>& board){
        int strow = 3*(row/3);
        int stcol = 3*(col/3);
        for(int i=strow; i<strow+3; i++){
            for(int j=stcol; j<stcol+3; j++){
                if(board[i][j]==c)
                    return false;
            }
        }
        return true;
    }
    bool isVal(int row, int col, char c, vector<vector<char>>& board){
        if(chkRow(row, c, board) && chkCol(col, c, board) && chkBox(row, col, c, board))
            return true;
        return false;
    }
    
    bool solve(int row, int col, vector<vector<char>>& board){
        //row = row+col/9
        //col = (col+1)%9
        if(row==9){
            return true;
        }
        if(board[row][col]!='.'){
            return solve(row+(col+1)/9, (col+1)%9, board);
        }
        else{
            for(int num=1; num<=9; num++){
                char p  = '0'+num;
                if(isVal(row, col, p, board)){
                board[row][col]=p;
                bool b = solve(row+(col+1)/9, (col+1)%9, board);
                if(!b){
                    board[row][col]='.';
                }
                    else
                        return true;
            }
            }
            return false;
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool bb = solve(0, 0, board);
    }
};