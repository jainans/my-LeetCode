class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mino = INT_MAX;
        int ans=0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]>mino){
                ans+=prices[i]-mino;
                mino= prices[i];
            }
            mino= min(mino, prices[i]);
        }
        return ans;
    }
};