class Solution {
public:
    bool isSub(string a, string b){
        if(a=="")
            return true;
        if(b.size()<a.size())
            return false;
        int k=0;
        for(int i=0; i<b.size(); i++){
            if(b[i]==a[k]){
                k++;
                if(k==a.size())
                    break;
            }
        }
        if(k==a.size())
            return true;
        return false;
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans=-1;
        for(int i=0; i<n; i++){
            string a = strs[i];
            int j=0;
            for(; j<n; j++){
                if(j==i)continue;
                if(isSub(a, strs[j]))break;
            }
            if(j==n){
                int y = strs[i].size();
                ans = max(ans, y);
            }
        }
        return ans;
        
    }
};