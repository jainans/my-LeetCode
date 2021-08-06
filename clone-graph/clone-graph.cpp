/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    static const int N= 102;
    int vis[N];
   
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<int, Node*>mp;
        Node* clone = new Node(node->val);
        mp[node->val]=clone;
        queue<Node* >q;
        q.push(node);
        vis[node->val]=1;
        while(!q.empty()){
            Node* p= q.front();
            q.pop();
            for(auto child : p->neighbors){
                if(vis[child->val]==0){
                    Node* y = new Node(child->val);
                    vis[child->val]=1;
                    mp[child->val] = y;
                    q.push(child);
                }
                mp[p->val]->neighbors.push_back(mp[child->val]);
                
            }
        }
        return clone;
    }
};