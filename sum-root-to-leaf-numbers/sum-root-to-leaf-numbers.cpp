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
    int ans;
    void solve(TreeNode* root, int p){
       if(root->left==NULL && root->right==NULL){
           ans+=p*10+root->val;
           return;
       }
       if(root->left)
           solve(root->left, p*10+root->val);
        if(root->right)
            solve(root->right, p*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};