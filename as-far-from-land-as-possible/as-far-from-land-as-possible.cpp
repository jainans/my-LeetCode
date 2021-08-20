int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // jungle ki aag type
        // bas source ek nhi saare h
        // ek kagaj ko 4 tarf se jalao to beech ka part sabse dur hota ji
        int n= grid.size();
        vector<vector<int> >vis(n, vector<int>(n, 0));
        vector<vector<int> >dis(n, vector<int>(n, 1e9));
        queue<pair<int, int> >q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                    dis[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        int ans= -1;
        while(!q.empty()){
            int pr = q.front().first;
            int pc = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int r = pr+dx[i];
                int c = pc+dy[i];
                if(r>=0 && r<n && c>=0 && c<n && vis[r][c]==0){
                    dis[r][c]=  dis[pr][pc]+1;
                    ans = max(ans, dis[r][c]);
                    vis[r][c]=1;
                    q.push({r, c});
                }
            }
        }
        return ans;
    }
};