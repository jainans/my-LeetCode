
class Solution {
public:
    int func(string s){
        int ans=0;
            for(int i=0; i<s.size(); i++){
                int p = s[i]-'0';
                ans = ans*10+p;
            }
        return ans;
    }
    vector<int> solve(vector<string>& v, int l, int r){
        if(l==r){
            int p = func(v[l]);
            vector<int>temp;
            temp.push_back(p);
            return temp;
        }
        vector<int>temp;
        for(int i=l; i<=r; i++){
            if(v[i]=="+" || v[i]=="-" || v[i]=="*"){
                vector<int>v1 = solve(v, l, i-1);
                vector<int>v2  =solve(v, i+1, r);
                for(int j=0; j<v1.size(); j++){
                    for(int k=0; k<v2.size(); k++){
                        if(v[i]=="+")
                            temp.push_back(v1[j]+v2[k]);
                        else if(v[i]=="-")
                            temp.push_back(v1[j]-v2[k]);
                        else
                            temp.push_back(v1[j]*v2[k]);
                    }
                }
            }
        }
        return temp;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<string>v;
        string s="";
        for(int i=0; i<n; i++){
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
                v.push_back(s);
                s = expression[i];
                v.push_back(s);
                s="";
                }
            else{
                s+=expression[i];
            }
        }
        v.push_back(s);

        vector<int>ans = solve(v, 0, v.size()-1);
        return ans;
    }
};