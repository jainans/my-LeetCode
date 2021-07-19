class Solution {
public:
   int mod = 1e9+7;
   int fact[1001];
   int bipow(int x, int n){
       int res = 1;
       while(n){
           if(n%2==0){
               x = (x*1LL*x)%mod;
               n/=2;
           }
           else{
               res=  (res*1LL*x)%mod;
               n--;
           }
       }
       return res;
   }
    int rev(int n){
        return bipow(n, mod-2);
    }
    int comb(int n, int r){
        if(n<=0 || r<0 || n<r)
            return 0;
        int p = fact[n];
        int rr= (rev(fact[n-r])*1LL*rev(fact[r]))%mod;
        p = (p*1LL*rr)%mod;
        return p;
    }
    
    int solve(vector<int>&nums){
        if(nums.size()<=2)
            return 1;
        vector<int>lef;
        vector<int>rit;
        for(auto i : nums){
            if(i<nums[0])
                lef.push_back(i);
            else if(i>nums[0])
                rit.push_back(i);
        }
        int p= solve(lef);
        int q = solve(rit);
        int r = comb(lef.size()+rit.size(), rit.size());
        r =(r*1LL*q)%mod;
        r = (r*1LL*p)%mod;
        return r;
        
        
    }
int numOfWays(vector<int>& nums) {
        
    int n= nums.size();
    int p=1;
    fact[0]=1;
    for(int i=1; i<=n; i++){
        fact[i] = (fact[i-1]*1LL*i)%mod; 
    }
    return solve(nums)-1;
}
};