class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(i!=j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }
        int l=0;
        int r= n-1;
        while(l<r){
            for(int i=0; i<n; i++){
                swap(matrix[i][l], matrix[i][r]);
            }
            l++;
            r--;
        }
    }
};