class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>v;
        v.push_back(0);
        v.push_back(1);
        if(n==1)
            return v;
        for(int i=2; i<=n; i++){
            for(int j=0; j<v.size(); j++)
                v[j]*=2;
            int p = v.size();
            for(int j=p-1; j>=0; j--)
                v.push_back(v[j]+1);
        }
        return v;
    }
};