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
    vector<TreeNode*> solve(int st, int end){
        vector<TreeNode*> ans;
        if(end-st+1==0){
            TreeNode* p = NULL;
            ans.push_back(p);
            return ans;
        }
        if(end==st){
            TreeNode* p = new TreeNode(st);
            ans.push_back(p);
            return ans;
        }

        for(int i=st; i<=end; i++){
           
            vector<TreeNode*>q = solve(st, i-1);
            vector<TreeNode*>r = solve(i+1, end);
            for(int k=0; k<q.size(); k++){
                for(int j=0; j<r.size(); j++){
                    TreeNode* p = new TreeNode(i);
                    p->left = q[k];
                    p->right = r[j];
                    ans.push_back(p);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};