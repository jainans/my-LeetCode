#define ll long long int
const ll mod = 1e9+7;
ll kadane(vector<int>& arr){
    ll maxo = INT_MIN;
    ll mxtill = 0;
    for(ll i=0; i<arr.size(); i++){
        if(mxtill+arr[i]<arr[i])
            mxtill =arr[i];
        else
            mxtill+=arr[i];
        maxo = max(maxo, mxtill);
    }
    return maxo;
}

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        ll tot=0;
        for(auto & i : arr){
            tot+=i;
        }
        if(k==1)
            return kadane(arr);
        ll n = arr.size();
        ll mxSf=arr[n-1];
        ll s = mxSf;
        for(ll i=n-2; i>=0; i--){
            s+=arr[i];
            mxSf = max(mxSf, s);
        }
        ll mxPf = arr[0];
        s=mxPf;
        for(ll i=1; i<n; i++){
            s+=arr[i];
            mxPf= max(s, mxPf);
        }
        if(tot>0){
            return (max({kadane(arr), (k-2)*tot+mxSf+mxPf, 0LL}))%mod;
        }
        return (max({kadane(arr), mxSf+mxPf, 0LL}))%mod;
    }
};