class Solution {
public:
    vector<char> rotate(vector<char>& line, int n){
        int r  = n;
        int l=n-1;
        while(l>=0){
        while(l>=0 && line[l]!='*'){
            l--;
        }
            int num=0;
           for(int i=l+1; i<r; i++){
               if(line[i]=='#')
                   num++;
           }
            for(int i=r-1; i>=l+1; i--){
                if(num>0){
                    line[i]='#';
                    num--;
                }
                else
                    line[i]='.';
            }
            r =l;
            l--;
        }
        return line;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        for(int i=0; i<n; i++){
            box[i] = rotate(box[i], m);
        }
        vector<vector<char> >ans(m, vector<char>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = box[n-1-j][i];
            }
        }
        return ans;
    }
};