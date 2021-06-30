class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        map<pair<int, int>, int>mp;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int p = board[i][j]-'0';
                    int db= 18+3*(i/3)+(j/3);
                    if(mp[{i, p}]==1 || mp[{j+9, p}]==1 || mp[{18+db, p}]==1)
                        return false;
                    mp[{i, p}]=1;
                    mp[{j+9, p}]=1;
                    mp[{18+db, p}]=1;
                }
            }
        }
        return true;
    }
};