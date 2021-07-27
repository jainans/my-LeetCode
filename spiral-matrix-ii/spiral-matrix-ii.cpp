class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> >mat(n, vector<int>(n, 0));
        int l=0;
        int r=0;
        int dirc=0;
        int p=1;
        while(p<=n*n){
           if(dirc==0){
               while(r<n && mat[l][r]==0 && p<=n*n){
                   mat[l][r]=p;
                   p++;
                   r++;
               }
               r--;
               l++;
               dirc=1;
           }
          else if(dirc==1){
              while(l<n && mat[l][r]==0 && p<=n*n){
                  mat[l][r]=p;
                  p++;
                  l++;
              }
              l--;
              r--;
              dirc=2;
          }
          else if(dirc==2){
              while(r>=0 && mat[l][r]==0 && p<=n*n){
                  mat[l][r]=p;
                  p++;
                  r--;
              }
              r++;
              l--;
              dirc=3;
          }  
          else{
              while(l>=0 && mat[l][r]==0 && p<=n*n){
                  mat[l][r]=p;
                  p++;
                  l--;
              }
              l++;
              r++;
              dirc=0;
          }  
        }
        return mat;
    }
};