class Solution {
public:
    string decodeString(string s) {
       
        string ans= "";
        
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=']')
                st.push(s[i]);
            else
            {
               string curr="";
                while(!st.empty() && st.top()!='['){
                    curr = st.top()+curr;
                    st.pop();
                }
                int p=1;
                st.pop();
                int num=0;
                while(!st.empty() && (st.top()-'0')>=0 && (st.top()-'0')<=9)
                {
                    num = num+p*(st.top()-'0');
                    p*=10;
                    st.pop();
                }
                string y="";
                for(int j=0; j<num; j++)
                    y+=curr;
                curr =y;
               for(int j=0; j<curr.size(); j++)
                   st.push(curr[j]);
            }
        }
        string pur="";
        while(!st.empty())
        {
            pur = st.top()+pur;
            st.pop();
        }
        ans+=pur;
        return ans;
    }
};