class Solution {
public:
    int tribonacci(int n) {
        int p=0;
        int q=1;
        int r =1;
        if(n==0)
            return p;
        if(n==1 || n==2)
            return q;
        int res;
        for(int i=3; i<=n; i++){
            res = p+q+r;
            p=q;
            q=r;
            r=res;
        }
        return res;
    }
};