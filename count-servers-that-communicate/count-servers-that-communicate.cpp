class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        vector<int>rows(m, 0);
        vector<int>cols(n, 0);
        int p=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                {
                    p++;
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<m; i++){
            if(rows[i]==1){
                for(int j=0; j<n; j++){
                    if(grid[i][j]==1){
                        if(cols[j]==1)
                            cnt++;
                    }
                }
            }
        }
        return p-cnt;
    }
};