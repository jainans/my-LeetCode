class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int> >v(n, vector<int>(m));
       
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                if(rowSum[i]<=colSum[j]){
                    v[i][j]=rowSum[i];
                    rowSum[i]=0;
                    colSum[j]-=v[i][j];
                }
                else{
                    v[i][j] = colSum[j];
                    rowSum[i]-=colSum[j];
                    colSum[j]=0;
                }
                
            }
        }
        return v;
    }
};