#define ll long long int
class Solution {
public:
    
    int nthUglyNumber(int n) {
       vector<ll>v(n+1);
        v[1]=1;
        int two=1;
        int three=1;
        int five=1;
        int p, q, r;
        for(int i=2; i<=n; i++){
            p = 2*v[two];
            q = 3*v[three];
            r = 5*v[five];
            v[i]=  min(p, min(q, r));
            if(v[i]==p)
                two++;
            if(v[i]==q)
                three++;
            if(v[i]==r)
                five++;
        }
        return v[n];
    }
        
};