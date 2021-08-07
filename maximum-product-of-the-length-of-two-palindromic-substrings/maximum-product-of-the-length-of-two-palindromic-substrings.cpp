
class Solution {
public:
    long long maxProduct(string s) {
        int n = s.size();
        int d1[n];
        int l=0;
        int r=-1;
        for(int i=0; i<n; i++){
            d1[i]=1;
            int k=1;
            if(i<=r){
                k= min(d1[r+l-i], r-i+1);
            }
            while(i-k>=0 && i+k<n && s[i-k]==s[i+k]){
                k++;
            }
            d1[i]=k;
            if(i+k-1>r){
                r = i+k-1;
                l=i-k+1;
            }
        }
        int st[n];
        int ed[n];
        int maxR = -1;
        for(int i=0; i<n; i++){
            if(d1[i]+i-1>maxR){
                for(int j=maxR+1; j<=d1[i]+i-1; j++){
                    st[j] = 2*(j-i)+1;
                }
                maxR = d1[i]+i-1;
            }
        }
        int minL = n;
        for(int i=n-1; i>=0; i--){
            if(i-d1[i]+1<minL){
                for(int j=minL-1; j>=i-d1[i]+1; j--){
                    ed[j] = 2*(i-j)+1;
                }
                minL = i-d1[i]+1;
            }
        }
        
        for(int i=1; i<n; i++){
            st[i] = max(st[i-1], st[i]);
        }
        for(int i=n-2; i>=0; i--){
            ed[i]=max(ed[i], ed[i+1]);
        }
        long long int ans=0;
        for(int i=0; i<n-1; i++){
            ans = max(ans, st[i]*1LL*ed[i+1]);
        }
        return ans;
    }
};