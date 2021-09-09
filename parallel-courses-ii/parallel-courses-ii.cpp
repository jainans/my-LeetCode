class Solution {
public:
    
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        
        
        vector<int>pre(n, 0);
        for(int i=0; i<relations.size(); i++){
            int p = relations[i][0]-1;
            int q = relations[i][1]-1;
            pre[q] |= (1 << p);
        }
        vector<int>maskpre((1 << n), 0);
        vector<int>bits((1 << n), 0);
        for(int i=0; i<(1 << n); i++){
            for(int j=0; j<n; j++){
                if(i & (1 << j))
                    maskpre[i] |= pre[j];
            }
            if(i!=0)
                bits[i] = 1+ bits[(i & (i-1))];
        }
        
        
        vector<int>dp((1 << n), n+1);
        dp[0]=0;
        for(int i=1; i < (1 << n); i++){
            for(int j=i; j; j=((j-1) & i)){
               
                if(bits[j] >k)
                    continue;
                if((maskpre[j] & (i ^ j)) == maskpre[j])
                    dp[i] = min(dp[i], 1+dp[i^j]);
            }
        }
        return dp[(1 << n)-1];
        
        
    }
};