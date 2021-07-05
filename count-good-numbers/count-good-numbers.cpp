#define ll long long int
class Solution {
public:
    ll mod = 1e9+7;
    ll bipow(ll x, ll n){
        ll res =1;
        while(n){
            if(n%2){
                res = (res*x)%mod;
                n--;
            }
            else{
                x = (x*x)%mod;
                n/=2;
            }
            
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        ll p = (n+1)/2;
        ll q = n/2;
        ll ans = bipow(5, p);
        ll r = bipow(4, q);
        ans = (ans*r)%mod;
        return ans;
    }
};