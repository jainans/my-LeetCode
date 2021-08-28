class Solution {
public:
    double champagneTower(int poured, int R, int C) {
        vector<vector<double> >v(R+2, vector<double>(R+2, 0));
        int curr = poured;
        if(curr==0)
            return 0.0000;
        v[0][0]=1.0000;
        v[1][0]= (curr-1)*1.000/2;
        v[1][1] = (curr-1)*1.000/2;
        
        for(int i=1; i<=R; i++){
            for(int j=0; j<=i; j++){
                if(v[i][j]>1.000){
                    
                    v[i+1][j]+=(v[i][j]-1.00)*1.00/2;
                    v[i+1][j+1]+=(v[i][j]-1.00)*1.00/2;
                    v[i][j]=1.00000;
                }
            }
        }
        return v[R][C];
    }
};