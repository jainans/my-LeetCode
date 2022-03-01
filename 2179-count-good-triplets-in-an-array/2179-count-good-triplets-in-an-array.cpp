class Solution {
public:
    #define ll long long int
    ll getSum(ll id, vector<ll>& bit){
        ll res=0;
        while(id){
            res += bit[id];
            id -= (id & (-id));
        }
        return res;
    }
    void update(ll id, vector<ll>& bit, ll add){
        ll n = bit.size();
        while(id<n){
            bit[id]+=add;
            id += (id & (-id));
        }
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<ll, ll>pos1;
        map<ll, ll>pos2;
        for(ll i=0; i<n; i++){
            pos1[nums1[i]]=i+1;
            pos2[nums2[i]]=i+1;
        }
        vector<ll>prenum(n, 0);
        vector<ll>aftnum(n, 0);
        vector<ll>prebit(n+1, 0);
        vector<ll>aftbit(n+1, 0);
        update(pos2[nums1[0]], prebit, 1LL);
        for(ll i=1; i<n; i++){
            ll x = pos2[nums1[i]];
            ll y = getSum(x-1, prebit);
            prenum[i]=y;
            update(x, prebit, 1LL);
        }
        update(pos2[nums1[n-1]], aftbit, 1LL);
        for(ll i=n-2; i>=0; i--){
            ll x = pos2[nums1[i]];
            ll y = getSum(x, aftbit);
            aftnum[i] = n-i-1-y;
            update(x, aftbit, 1LL);
        }
        ll ans=0;
        for(ll i=0; i<n; i++){
            ans += (prenum[i]*1LL*aftnum[i]);
        }
        return ans;
    }
};