class Solution {
public:
    string longestPalindrome(string s) {
        int n=  s.size();
        int d1[n];
        int d2[n];
        d1[0]=1;
        int l=0;
        int r=0;
        d2[0]=0;
        int l2= 0;
        int r2=0;
        int maxl=0;
        int st;
        int ed;
        if(n==1)
            return s;
        for(int i=1; i<n; i++){
            if(i<r)
            d1[i] = min(r-i+1, d1[l+r-i]);
            else
               d1[i]=1;
            while(i-d1[i]>=0 && i+d1[i]<n && s[i-d1[i]]==s[i+d1[i]])
                d1[i]++;
            if(i+d1[i]-1>r){
                r = i+d1[i]-1;
                l = i-d1[i]+1;
            }
            if(i<r2)
            d2[i] = min(r2-i+1, d2[l2+r2-i]);
            else
                d2[i]=0;
            while(i-d2[i]-1>=0 && i+d2[i]<n && s[i-d2[i]-1]==s[i+d2[i]])
                d2[i]++;
            if(i+d2[i]-1>r2){
                r2 = i+d2[i]-1;
                l2 = i-d2[i];
            }
            if(2*d1[i]-1>maxl){
                maxl = 2*d1[i]-1;
                st = i-d1[i]+1;
                ed = i+d1[i]-1;
            }
            if(2*d2[i]>maxl){
                maxl = 2*d2[i];
                st = i-d2[i];
                ed = i+d2[i]-1;
            }
        }
        // for(int i=0; i<n; i++){
        //     cout<<d1[i]<<" ";
        // }
        // cout<<endl;
        //   for(int i=0; i<n; i++){
        //     cout<<d2[i]<<" ";
        // }
        // cout<<endl;
        string ans = s.substr(st, ed-st+1);
        return ans;
    }
};