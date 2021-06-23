class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = 0;
        int minprice=INT_MAX;
        int prof=0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<minprice){
                minprice = prices[i];
            }
            else{
                prof = prices[i]-minprice;
                maxprof = max(maxprof, prof);
            }
        }
        return maxprof;
        
    }
};