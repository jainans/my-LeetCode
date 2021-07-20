#define ll long long int
class Solution {
public:
    ll cnt;
    void merge(ll l, ll r, ll mid, vector<ll>& pref){
        ll lf = mid-l+1;
        ll rt = r-mid;
        auto left = new ll[lf];
        auto right  =  new ll[rt];
        for(int i=0; i<lf; i++){
            left[i] = pref[l+i];
        }
        for(int i=0; i<rt; i++){
            right[i] = pref[mid+1+i];
        }
        ll p=0;
        ll q=0;
        ll k=l;
        while(p<lf && q<rt){
            if(left[p]<=right[q]){
                pref[k]=left[p];
                p++;
                k++;
            }
            else{
                pref[k] = right[q];
                q++;
                k++;
            }
        }
        while(p<lf){
             pref[k]=left[p];
                p++;
                k++;
        }
        while(q<rt){
             pref[k] = right[q];
                q++;
                k++;
        }
        
    }
    
    void merge_sort(ll l, ll r, vector<ll>& pref, ll lower, ll upper){
        if(l>=r)
            return ;
        ll mid= l+(r-l)/2;
        merge_sort(l, mid, pref, lower, upper);
        merge_sort(mid+1, r, pref, lower, upper);
        ll pp=mid+1;
        ll qq = mid+1;
        for(ll i=l; i<=mid; i++){
            while(pp<=r && pref[pp]<pref[i]+lower){
                pp++;
            }
           
            while(qq<=r && pref[qq]-pref[i]<=upper)
                qq++;
            ll y=0;
            cnt+=max(qq-pp, y);
        }
        merge(l, r, mid, pref);
        
    }
    
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //BASIC IDEA is to use merge sort to use divide and conquer strategy 
        //apply merge sort on prefix sum;
         cnt=0;
        ll n = nums.size();
        vector<ll>pref(n);
        pref[0]=nums[0];
        for(ll i=1; i<n; i++)
        {
            pref[i]=pref[i-1]+nums[i];
        }
        for(ll i=0; i<n; i++){
            if(pref[i]>=lower && pref[i]<=upper)
                cnt++;
        }
        ll x=0;
        merge_sort(x, n-1, pref, lower, upper);
        return cnt;
    }
};