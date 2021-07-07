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
    ll inv(ll p){
        return bipow(p, mod-2);
    }
    ll fec[100001];
    ll C(ll n, ll r){
        if(n<r || n<0 || r<0)
            return 0;
        ll p = fec[n];
        ll q = fec[n-r];
        q = (q*fec[r])%mod;
        ll rr = inv(q);
        p = (p*rr)%mod;
        return p;
    }
    pair<ll, ll>dp[100001];
    pair<ll, ll> dfs(ll node, vector<vector<ll> >& adj, ll n){
        if(adj[node].size()==0)
            return dp[node]= {1, 1};
        if(dp[node].first!=-1)
            return dp[node];
        
            pair<ll, ll>p =  dfs(adj[node][0], adj, n);
         if(adj[node].size()==1)
         {
             pair<ll, ll>q;
             q.first = p.first;
             q.second = p.second+1;
             return q;
         }
        ll cnt =  p.second;
        ll nas = p.first;
        for(ll i=1; i<adj[node].size(); i++){
            pair<ll, ll>r = dfs(adj[node][i], adj, n);
            cnt+=r.second;
            ll d = C(cnt, r.second);
           ll dd = (d*r.first)%mod;
            nas = (nas*dd)%mod;
        }
        return dp[node]  = {nas, cnt+1};
            
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        ll n = prevRoom.size();
        vector<vector<ll> >adj(n);
        ll res =1;
        fec[0]=fec[1]=1;
        dp[0] = {-1, -1};
        for(ll i=1; i<n; i++){
            adj[prevRoom[i]].push_back(i);
            fec[i+1] = (fec[i]*(i+1))%mod;
            dp[i] = {-1, -1};
        }
        pair<ll, ll>pp = dfs(0, adj, n);
        return pp.first;
    }
};