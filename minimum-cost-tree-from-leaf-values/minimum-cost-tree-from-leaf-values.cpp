const int N = 41;
int dp[N][N];
int pp[N][N];
class Solution {
public:
    int solve(int l, int r, vector<int>& arr){
        if(l>=r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        dp[l][r]=INT_MAX;
        for(int i=l; i<r; i++){
            dp[l][r]=  min(dp[l][r], pp[l][i]*pp[i+1][r]+solve(l, i, arr)+solve(i+1, r, arr));
        }
        return dp[l][r];
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j]=-1;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(j<i)
                    continue;
                if(i==j)
                    pp[i][j]=arr[i];
                else{
                    pp[i][j]=max(arr[j], pp[i][j-1]);
                }
            }
        }
        return solve(0, n-1, arr);
    }
};