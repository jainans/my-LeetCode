class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dp[12][12][11];
    int dfs(int st, int x, int y, string word, vector<vector<char>>& board, vector<vector<int> >& vis){
         if(st==word.size())
             return dp[x][y][st]= 1;
        if(dp[x][y][st]!=-1)
            return dp[x][y][st];
        vis[x][y] = 1;
        for(int i=0; i<4; i++){
            int cx = x+dx[i];
            int cy = y+dy[i];
            if(cx>=0 && cx<board.size() && cy>=0 && cy<board[0].size()){
                if(vis[cx][cy]==0 && board[cx][cy]==word[st] && dfs(st+1, cx, cy, word, board, vis)){
                    return dp[x][y][st]= true;
                }
                    
            }
        }
        vis[x][y]=0;
        return dp[x][y][st]= false;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        
        int n = board.size();
        int m  = board[0].size();
        vector<vector<int> >vis(n, vector<int>(m, 0));
        for(int i=0; i<words.size(); i++){
           for(int a=0; a<12; a++){
               for(int b=0; b<12; b++){
                   for(int c=0; c<11; c++){
                       dp[a][b][c]= -1;
                   }
               }
           }
            for(int j=0; j<n; j++){
                
                for(int k=0; k<m; k++){
                   
                    if(board[j][k]==words[i][0]){
                        for(int p=0; p<n; p++){
                            for(int q=0; q<m; q++)
                                vis[p][q]=0;
                        }
                        int bb = dfs(1, j, k, words[i], board, vis);
                        
                        if(bb==1){
                            ans.push_back(words[i]);
                           
                        }
                        
                    }
                   
                }
               
            }
        }
        set<string>vans;
        for(int i=0; i<ans.size(); i++){
            vans.insert(ans[i]);
        }
        ans.clear();
        for(auto it : vans){
            ans.push_back(it);
        }
        return ans;
    }
};