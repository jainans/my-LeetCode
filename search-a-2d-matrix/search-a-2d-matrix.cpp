class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l=0;
        int r = n*m-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int p = mid/m;
            int q = mid%m;
            if(matrix[p][q]==target)
                return true;
            else if(matrix[p][q]<target){
                l= mid+1;
            }
            else
                r = mid-1;
        }
        return false;
    }
};