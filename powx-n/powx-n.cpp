class Solution {
public:
    double bipow(double x, long long int n){
        double res = 1.000;
        while(n){
            if(n%2==0){
                x = double(x*x);
                n/=2;
            }
            else{
                res = double(res*x);
                n--;
            }
        }
        return res;
    }
    double myPow(double x, int n) {
        if(n==0)
            return 1.0000;
        long long int p = n;
        if(p<0){
            x = double(1.000/x);
        }
        p = abs(p);
        return bipow(x, p);
    }
};