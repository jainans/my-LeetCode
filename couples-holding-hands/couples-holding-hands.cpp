class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        // the inversion is :  i = ptn[pos[ptn[row[i]]]]
        vector<int>pos(n, 0);
        vector<int>ptn(n, 0);
        for(int i=0; i<n; i++){
            pos[row[i]]=i;
            ptn[i] = ((i%2==0) ? (i+1) :  (i-1));
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j = ptn[pos[ptn[row[i]]]]; j!=i; j =ptn[pos[ptn[row[i]]]])
            {
                swap(pos[row[i]], pos[row[j]]);
                swap(row[i], row[j]);
                ans++;
            }
        }
        return ans;
    }
};