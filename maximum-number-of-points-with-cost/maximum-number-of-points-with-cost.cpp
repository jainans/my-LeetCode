#define ll long long int
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        ll n = points.size();
        ll m = points[0].size();
        vector<ll>pref(m);
        vector<ll>dp(m);
        for(ll i=0; i<m; i++)
            dp[i]=points[0][i];
        pref[0]=points[0][0]+0;
        for(ll i=1; i<m; i++){
            pref[i] = max(pref[i-1], points[0][i]*1LL+i);
        }
        vector<ll>suff(m);
        suff[m-1]=points[0][m-1]-m+1;
        for(ll i=m-2; i>=0; i--){
            suff[i]=max(suff[i+1], points[0][i]*1LL-i);
        }
        
        for(ll i=1; i<n; i++){
            for(ll j=0; j<m; j++){
                  ll x= points[i][j]+pref[j]-j;
                if(j!=m-1){
                    x=  max(x, points[i][j]*1LL+j+suff[j+1]);
                }
                dp[j] = x;
                
            }
            pref[0]=dp[0]+0;
        for(ll j=1; j<m; j++){
            pref[j] = max(pref[j-1], dp[j]+j);
        }
        suff[m-1]=dp[m-1]-m+1;
        for(ll j=m-2; j>=0; j--){
            suff[j]=max(suff[j+1], dp[j]*1LL-j);
        }
          
        }
        
        ll ans = INT_MIN;
        for(ll i=0; i<m; i++){
            ans = max(ans, dp[i]);
        }
       
        return ans;
        
    }
};