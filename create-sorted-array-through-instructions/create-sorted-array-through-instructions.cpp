#define ll long long int
const ll mod = 1e9+7;
class Solution {
public:
    ll getSum(ll id, vector<ll>& BIT){
        ll sum=0;
        while(id>0){
            sum+=BIT[id];
            id -= (id & (-id));
        }
        return sum;
    }
    
    void update(ll id, vector<ll>& BIT, ll val){
        while(id<BIT.size()){
            BIT[id]+=val;
            id+=(id & (-id));
        }
    }
    
    int createSortedArray(vector<int>& instructions) {
        ll n = instructions.size();
        vector<ll>nums(instructions.begin(), instructions.end());
        sort(nums.begin(), nums.end());
        for(ll i=0; i<instructions.size(); i++){
            instructions[i]= lower_bound(nums.begin(), nums.end(), instructions[i])-nums.begin()+1;
        }
        ll ans=0;
        vector<ll>BIT(n+1, 0);
        for(ll i=0; i<n; i++){
            ll p = getSum(instructions[i]-1, BIT);
            ll q = getSum(instructions[i], BIT);
            q = i-q;
            ans+=min(p , q);
            update(instructions[i], BIT, 1);
        }
        return ans%mod;
    }
};