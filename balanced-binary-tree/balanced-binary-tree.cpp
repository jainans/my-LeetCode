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
    int solve(TreeNode* root, bool & bb){
        if(!root)
            return 0;
        int p = solve(root->left, bb);
        int q = solve(root->right, bb);
        if(abs(p-q)>1)
            bb= false;
        return 1+max(p, q);
    }
    bool isBalanced(TreeNode* root) {
       bool bb =true;
        solve(root, bb);
        return bb;
    }
};