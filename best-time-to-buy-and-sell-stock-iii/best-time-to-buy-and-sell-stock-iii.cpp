class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>pref(n);
        int mino = prices[0];
        int loss = 0;
        pref[0]=0;
        for(int i=1; i<n; i++){
            if(prices[i]<mino){
                mino  = prices[i];
                pref[i]=pref[i-1];
            }
            else
                pref[i] = max(pref[i-1], prices[i]-mino);
        }
        int ans = pref[n-1];
        int maxo = 0;
        for(int i=n-1; i>=0; i--){
            if(prices[i]>maxo){
                maxo =  prices[i];
                ans = max(ans, loss+pref[i]);
            }
            else{
                loss = max(loss, maxo-prices[i]);
                ans = max(ans,pref[i]+loss);
            }
        }
        return ans;
    }
};