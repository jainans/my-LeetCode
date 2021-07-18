class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        int p = 0;
        int q = n-1;
        int r = m-1;
        int s=0;
        vector<int>ans;
        while(p<=q && s<=r){
            for(int i=s; i<=r; i++)
                ans.push_back(matrix[p][i]);
            p++;
             if(p>q)
                break;
            for(int i=p; i<=q; i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(r<s)
                break;
           
            for(int i=r; i>=s; i--){
                ans.push_back(matrix[q][i]);
            }
            q--;
            if(q<p)
                break;
            for(int i=q; i>=p; i--)
                ans.push_back(matrix[i][s]);
            s++;
            if(s>r)
                break;
        }
        return ans;
    }
};