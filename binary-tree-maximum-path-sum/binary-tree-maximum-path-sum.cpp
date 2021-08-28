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
    int ans=INT_MIN;
    int maxSum(TreeNode* root){
        if(!root->left && !root->right){
            ans  = max(ans, root->val);
            return root->val;
        }
        int p= ((root->left) ? maxSum(root->left) :  0);
        int q = ((root->right) ? maxSum(root->right) :  0);
        int r = max(p, 0);
        int s = max(q, 0);
        ans = max(ans, root->val+r+s);
        return max(root->val , root->val + max(p, q));
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;
    }
};