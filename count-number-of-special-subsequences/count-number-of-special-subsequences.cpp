#define ll long long int
class Solution {
public:
    ll mod = 1e9+7;
    ll bipow(ll x, ll n){
        ll res=1;
        while(n){
            if(n%2==0){
                x = (x*x)%mod;
                n/=2;
            }
            else{
                res = (res*x)%mod;
                n--;
            }
        }
        return res;
    }
    ll rev(ll p){
        return bipow(p, mod-2);
    }
    int countSpecialSubsequences(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        ll one=0;
        for(ll i=0; i<nums.size(); i++){
            if(nums[i]==1)
                one++;
        }
        if(one==0)
            return 0;
        vector<ll>zeros;
        vector<ll>twos;
        ll z=0;
        ll t=0;
        for(ll i=0; i<nums.size(); i++){
            if(nums[i]==1){
                zeros.push_back(z);
                twos.push_back(t);
                z=0;
                t=0;
            }
            else{
                if(nums[i]==0)
                    z++;
                else
                    t++;
            }
        }
        zeros.push_back(z);
        twos.push_back(t);
        ll m = zeros.size();
        for(ll i=0; i<m; i++){
            if(i==0){
                zeros[i] = (bipow(2, zeros[i])-1+mod)%mod;
            }
            else{
                zeros[i] = (((zeros[i-1]+1)*(bipow(2, zeros[i])))%mod-1+mod)%mod;
            }
        }
        for(ll i=m-1; i>=0; i--){
            if(i==m-1){
                twos[i] = (bipow(2, twos[i])-1+mod)%mod;
            }
            else{
                twos[i] = (((twos[i+1]+1)*(bipow(2, twos[i])))%mod-1+mod)%mod;
            }
        }
       
        ll u=0;
        
        for(ll i=1; i<m; i++){
            if(i<=2)
                u = (u+twos[i]);
            else
                u = (u+bipow(2, i-2)*twos[i])%mod;
        }
        ll ans=0;
        ll yy = 1;
        for(ll i=0; i<m-1; i++){
            ans = (ans+zeros[i]*u)%mod;
            if(i<m-2){
            ll pp = (u+twos[yy+1]-twos[yy]+mod)%mod;
            ll qq = rev(2LL);
            u = (pp*qq)%mod;    
           yy++;
            }
        }
        return ans;
        
        
    }
};