class Solution {
public:
   
    vector<string> letterCombinations(string digits) {
        vector<string>given=  {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        
        int n = digits.size();
        if(n==0)
            return ans;
        string temp = "";
        ans.push_back(temp);
        for(auto digit : digits){
            vector<string>temp;
            for(auto s : ans){
            for(auto c : given[digit-'0']){
                temp.push_back(s+c);
            }
            }
            ans = temp;
        }
        return ans;
    }
};