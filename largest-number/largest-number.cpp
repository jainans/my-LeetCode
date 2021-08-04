class Solution {
public:
    static bool comp(int p, int q){
       string ps= "";
       string qs = "";
        if(p==0)
            ps="0";
        if(q==0)
            qs="0";
        
       while(p){
           char c = '0'+p%10;
           p/=10;
           ps = c+ps;
       }
       while(q){
           char c = '0'+q%10;
           q/=10;
           qs = c+qs;
       }
       int pl= ps.size();
        int ql = qs.size();
        int l=0;
        int r=0;
        while(l<pl && r<ql){
            if(ps[l]>qs[r])
                return true;
            else if(ps[l]<qs[r])
                return false;
            l++;
            r++;
        }
        if(l<pl){
            string gg = ps.substr(l);
            string h = gg+qs;
            string k = qs+gg;
            return (h>=k);
        }
       else if(r<ql){
           string gg = qs.substr(r);
            string h = gg+ps;
            string k = ps+gg;
            return (k>=h); 
        }
        return false;
        
        
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string ans="";
        for(auto p : nums){
            ans+=to_string(p);
        }
        bool bb =true;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]!='0'){
                bb=  false;
                break;
            }
        }
        string op = "0";
        if(bb)
            return op;
        return ans;
    }
};