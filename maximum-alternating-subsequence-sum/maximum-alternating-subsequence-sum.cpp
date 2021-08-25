#define ll long long int
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ll n = nums.size();
        ll odd = 0;
        ll even = nums[0];
        ll x, y;
        for(ll i=1; i<n; i++){
            x = max(even, odd+nums[i]*1LL);
            y = max(even-nums[i]*1LL, odd);
           
                even=x;
            odd =y;
        }
        return even;
    }
};