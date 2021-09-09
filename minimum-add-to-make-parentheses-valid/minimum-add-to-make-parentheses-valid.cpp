class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int cnt=0;
        int sum=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(')
                sum++;
            else
                sum--;
            if(sum<0){
                cnt++;
                sum=0;
            }
        }
        cnt+=sum;
        return cnt;
    }
};