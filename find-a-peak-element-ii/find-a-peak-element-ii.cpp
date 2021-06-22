class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol = 0;
        int endCol = mat[0].size()-1;
        vector<int>temp;
        while(startCol<=endCol){
            int maxRow=0;
            int midCol = startCol+(endCol-startCol)/2;
            for(int i=0; i<mat.size(); i++){
                maxRow = (mat[i][midCol]>mat[maxRow][midCol]) ? i : maxRow;
            }
            bool isLfBg = ((midCol-1>=startCol) && (mat[maxRow][midCol-1]>mat[maxRow][midCol]));
            bool isRtBg = ((midCol+1<=endCol) && (mat[maxRow][midCol+1]>mat[maxRow][midCol]));
            if(!isLfBg && !isRtBg){
                
                temp.push_back(maxRow);
                temp.push_back(midCol);
                return temp;
            }
            else if(isLfBg)
                endCol = midCol-1;
            else
                startCol = midCol+1;
        }
        return temp;
    }
};