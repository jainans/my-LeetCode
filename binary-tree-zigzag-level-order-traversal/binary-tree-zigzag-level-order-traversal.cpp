/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >ans;
        if(!root)
            return ans;
        queue<TreeNode* >q;
        q.push(root);
        int id=0;
        while(!q.empty()){
            int p =q.size();
            vector<int>v;
            for(int i=0; i<p; i++){
                v.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            if(id%2==0)
                ans.push_back(v);
            else{
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
            id++;
        }
        return ans;
    }
};