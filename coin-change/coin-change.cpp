class Solution {
public:
    const static int N = 1e4+3;
    int dp[N];
    int solve(vector<int>& coins, int num){
        if(num==0)
            return dp[num]=0;
        if(num<0)
            return 300000;
        if(dp[num]!=-2)
            return dp[num];
        dp[num]=10005;
        for(int i=0; i<coins.size(); i++){
            dp[num] = min(dp[num], 1+solve(coins, num-coins[i]));
        }
        return dp[num];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        sort(coins.begin(), coins.end());
        for(int i=0; i<=amount; i++)
            dp[i]=-2;
        int ans= solve(coins, amount);
        if(ans==300000 || ans==10005)
            return -1;
        return ans;
        
    }
};