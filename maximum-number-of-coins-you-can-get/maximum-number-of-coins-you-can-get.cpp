class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int l=0;
        int r = n-2;
        int ans=0;
        while(l<n/3){
            ans+=piles[r];
            l++;
            r-=2;
        }
        return ans;
    }
};