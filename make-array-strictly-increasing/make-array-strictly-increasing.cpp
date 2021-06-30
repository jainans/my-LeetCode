class Solution {
public:
   int dp[2001][2001];
    int m_val = 2001;
    int solve(int l, int r, vector<int>& arr1, vector<int>& arr2, int prev){
         if(l==arr1.size())
            return dp[l][r] = 0;
        r = upper_bound(arr2.begin(), arr2.end(), prev)-arr2.begin();
        if(r==arr2.size()){
            bool b= true;
            for(int i=l; i<arr1.size(); i++){
                if(arr1[i]<=prev)
                    b = false;
                prev = arr1[i];
            }
            if(b)
                return dp[l][r] =  0;
            return dp[l][r] =  m_val;
        }
        if(dp[l][r]==0){
            dp[l][r] = 1+solve(l+1, r+1, arr1, arr2, arr2[r]);
            if(arr1[l]>prev){
                dp[l][r] = min(dp[l][r], solve(l+1, r, arr1, arr2, arr1[l]));
            }
        }
        return dp[l][r];
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(), arr2.end());
       
        int p = solve(0, 0, arr1, arr2, -4);
        if(p>=m_val)
            return -1;
        return p;
    }
};