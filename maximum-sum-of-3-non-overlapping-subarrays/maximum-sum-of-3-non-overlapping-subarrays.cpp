class Solution {
public:
    
    int sum(vector<int>& pref, int k, int st){
        int ed = st+k-1;
        return pref[ed]-((st>0) ? pref[st-1] : 0);
    }
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        if(n<=2)
            return ans;
        if(n==3){
            ans.push_back(0);
            ans.push_back(1);
            ans.push_back(2);
                return ans;
        }
        vector<int>pref(n);
        pref[0]=nums[0];
        for(int i=1; i<n; i++){
            pref[i]=pref[i-1]+nums[i];
        }
        //we'll fix the middle position and try to find the first and last position
        //starting indices for middle -> [k, n-2*k]
        // middle start->i then first start check-> [0, i-k] and 
        //third start check->[i+k, n-k]
        
        // v1->stores max for first starting upto i;
        // v2->stores max for third start from i;
        
        vector<int>v1(n, 0);
        vector<int>v2(n, 0);
        int maxo = pref[k-1];
        v1[0]=0;
        for(int i=1; i<=n-3*k; i++){
            int q= pref[i+k-1]-pref[i-1];
            if(q>maxo){
                v1[i]=i;
                maxo = q;
            }
            else{
                v1[i]=v1[i-1];
            }
        }
        maxo = pref[n-1]-pref[n-1-k];
        v2[n-k]=n-k;
        for(int i=n-k-1; i>=2*k; i--){
            int q = pref[i+k-1]-pref[i-1];
            if(q>=maxo){
                v2[i]=i;
                maxo = q;
            }
            else{
                v2[i]=v2[i+1];
            }
        }
        int id = k;
        int mxsm = sum(pref, k , id)+sum(pref,k, v1[id-k])+sum(pref, k, v2[id+k]);
        for(int i=k+1; i<=n-2*k; i++){
            int x = sum(pref, k , i)+sum(pref,k, v1[i-k])+sum(pref, k, v2[i+k]);
            if(x>mxsm){
                id = i;
                mxsm = x;
            }
        }
       
        ans.push_back(v1[id-k]);
        ans.push_back(id);
        ans.push_back(v2[id+k]);
        return ans;
        
    }
};