class Solution {
public:
    #define ll long long int 
    string toStr(ll p){
        string ans="";
        if(p==0)
            return "0";
        bool bb =false;
        if(p<0)
            bb = true;
        p =abs(p);
        while(p){
            ll y = p%10;
            p/=10;
            ans=char('0'+y)+ans;
        }
        if(bb)
            ans= '-'+ans;
        return ans;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        ll n = nums.size();
        vector<string>res;
        string ans = "";
        ll l, r;
       
        for(ll i=0; i<n; i++){
            if(i==0){
                l=nums[0];
                r= nums[0];
            }
            else{
              if(nums[i]!=nums[i-1]+1){
                  ans += toStr(l);
                  if(r!=l)
                  {
                      ans+="->";
                      ans+=toStr(r);
                  }
                  res.push_back(ans);
                  ans="";
                  l=nums[i];
                  r=nums[i];
              }
                else{
                    r++;
                }
            }
        }
        if(n!=0){
            ans+=toStr(l);
            if(r!=l)
                  {
                      ans+="->";
                      ans+=toStr(r);
                  }
                  res.push_back(ans);
        }
        return res;
    }
};