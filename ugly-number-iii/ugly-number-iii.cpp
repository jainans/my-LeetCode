class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        //use of binary search in a very good manner
        //think of a function f(k) where f(k) is the number of positive integers that are divisble by either a, b, c and <=k
        //vane diagram
        long long int A = a;
        long long int B = b;
        long long int C = c;
        long long int N = n;
        long long int ab = A*B/__gcd(A, B);
        long long int bc = B*C/__gcd(B, C);
        long long int ac = A*C/__gcd(A, C);
        long long int abc = A*bc/__gcd(A, bc);
        long long int l = 1;
        long long int r = 2*1e9;
        long long int ans;
        while(l<r){
           long long int mid = l+(r-l)/2;
            long long int fmid = mid/A+mid/B+mid/C-mid/ab-mid/bc-mid/ac+mid/abc;
            if(fmid<N){
                l = mid+1;
            }
            else{
                
                r = mid;
            }
        }
        return l;
    }
};