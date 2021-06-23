class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>maxo(n);
        maxo[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--){
            maxo[i]=  max(maxo[i+1], prices[i]);
        }
        int nas=0;
        for(int i=0; i<n-1; i++){
            nas = max(nas, maxo[i+1]-prices[i]);
        }
        return nas;
    }
};