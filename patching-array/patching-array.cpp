#define ll long long int
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        vector<ll>v;
        bool bb = false;
        for(ll i=0; i<nums.size(); i++){
            if(nums[i]<n)
                v.push_back(nums[i]);
            else if(nums[i]==n){
                bb=  true;
                break;
            }
            
        }
        v.push_back(n);
        ll prev=0;
        ll cnt=0;
        for(ll i=0; i<v.size(); i++){
            while(prev<v[i]-1){
                prev+=prev+1;
                cnt++;
                if(prev>=n)
                    break;
            }
            if(i!=v.size()-1 || bb )
            prev+=v[i];
            if(prev>=n)
                break;
            
        }
        while(prev<n){
            prev+=prev+1;
            cnt++;
        }
        return cnt;
    }
};