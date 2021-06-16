class Solution {
public:
    const static int N = 102;
    int dp[N];
    int solve(string s, int id){
        if(id>=s.size())
            return 1;
        if(id==s.size()-1 && s[id]!='0')
            return dp[id]= 1;
        if(s[id]=='0')
            return dp[id]= 0;
        if(dp[id]!=-1)
            return dp[id];
        int y=99;
        if(id<s.size()-1){
        string u = s.substr(id, 2);
        int p = u[1]-'0';
        int q = u[0]-'0';
        y = p+10*q;
        }
        int xx = solve(s, id+1);
        int yy=0;
        if(id<s.size()-1 && y<=26)
            yy= solve(s, id+2);
        return dp[id] = xx+yy;
    }
    int numDecodings(string s) {
        for(int i=0; i<N; i++)
            dp[i]=-1;
        int nas = solve(s, 0);
        return nas;
    }
};