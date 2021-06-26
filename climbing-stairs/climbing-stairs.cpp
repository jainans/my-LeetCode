class Solution {
public:
    int climbStairs(int n) {
        int p = 1;
        int q = 1;
        if(n<=1)
            return 1;
        int r;
        for(int i=2; i<=n; i++){
            r = p+q;
            p = q;
            q = r;
        }
        return q;
    }
};