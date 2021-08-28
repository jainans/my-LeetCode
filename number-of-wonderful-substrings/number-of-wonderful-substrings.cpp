#define ll long long int
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        // aabb
        // n=4
        
        unordered_map<ll, ll>mp;
        mp[0]=1;
        ll ans=0;
        ll prev=0;
        for(ll i=0; i<n; i++){
            ll x = word[i]-'a';
            x++;
            ll y = (1 << x);
            y = y^prev;
           
            for(ll j=1; j<=10; j++){
                ll u = (1 << j)^y;
                ans+=mp[u];
            }
            ans+=mp[y];
            prev = y;
            mp[prev]++;
        }
       
        return ans;
    }
};