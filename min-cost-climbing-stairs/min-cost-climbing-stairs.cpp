class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==2)
            return min(cost[1], cost[0]);
        int fst = cost[0];
        int sec = cost[1];
        int p;
        for(int i=2; i<n; i++){
            p = cost[i]+min(fst, sec);
            fst = sec;
            sec= p;
        }
        return min(p, fst);
    }
};