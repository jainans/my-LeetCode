class Solution {
public:
    vector<int> maxNumber(vector<int> nums1, vector<int> nums2) {
    vector<int> out;
    while (nums1.size() + nums2.size()) {
        vector<int>& now = nums1 > nums2 ? nums1 : nums2;
        out.push_back(now[0]);
        now.erase(now.begin());
    }
    return out;
    }
    vector<int> solve(int k, vector<vector<int> >& pos, int prev, int n){
        vector<int>ans;
        vector<int>curr(10, 0);
        while(k>0){
            for(int i=9; i>=0; i--){
                while(curr[i]<pos[i].size() && pos[i][curr[i]]<=prev)
                    curr[i]++;
                if(curr[i]<pos[i].size() && pos[i][curr[i]]<=n-k){
                    ans.push_back(i);
                    prev = pos[i][curr[i]];
                    break;
                }
            }
            k--;
        }
        return ans;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int> >pos1(10);
        for(int i=0; i<n; i++){
            pos1[nums1[i]].push_back(i);
        }
        vector<vector<int> >pos2(10);
        for(int i=0; i<m; i++){
            pos2[nums2[i]].push_back(i);
        }
        
        int mino = (m>=k) ? 0 : k-m;
        int maxo = (n>=k) ? k : n;
        vector<int>ans;
        
        for(int i = mino; i<=maxo; i++){
           vector<int>ff = solve(i, pos1, -1,  n);
           vector<int>ss = solve(k-i, pos2, -1, m);
           ans = max(ans, maxNumber(ff, ss));
          
        }
        return ans;
    }
};