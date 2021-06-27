class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int>buy(k+1, INT_MIN);
        vector<int>sell(k+1, INT_MIN);
        buy[0]=sell[0]=0;
        int n = prices.size();
        if(n==0)
            return 0;
        for(int i=0; i<n; i++){
            for(int j=1; j<=k; j++){
                buy[j] = max(buy[j], sell[j-1]-prices[i]);
                sell[j] = max(sell[j], buy[j]+prices[i]);
            }
        }
        return sell[k];
    }
};