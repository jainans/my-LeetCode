class Solution {
public:
    bool isValidSerialization(string pre) {
        stack<pair<int, int> >s;
        int bt=0;
        int node=-1;
        if(pre.size()==1 && pre[0]=='#')
            return true;
        for(int i=0; i<pre.size(); i++){
            if(pre[i]=='#'){
                if(s.empty())
                    return false;
                while(!s.empty() && s.top().second==1)
                    s.pop();
                if(!s.empty()){
                    s.top().second=1;
                }
            }
            else if(pre[i]==','){
                if(node==-1)
                    continue;
                else{
                    if(s.empty() && bt==1)
                        return false;
                    s.push({node, 0});
                    bt=1;
                    node=-1;
                }
            }
            else{
              if(node==-1)
                  node=0;
                int q = pre[i]-'0';
                node = node*10+q;
            }
        }
        if(node!=-1)
            return false;
        if(!s.empty())
            return false;
        return true;
    }
};