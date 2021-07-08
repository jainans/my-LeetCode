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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(root==NULL)
            return ans;
        q.push(root);
        TreeNode* pre;
        while(!q.empty()){
            int p = q.size();
            for(int i=0; i<p; i++){
                pre=  q.front();
                q.pop();
                if(pre->left!=NULL)
                    q.push(pre->left);
                if(pre->right!=NULL)
                    q.push(pre->right);
            }
            ans.push_back(pre->val);
        }
        return ans;
    }
};