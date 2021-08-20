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
    int sum(TreeNode* root){
        if(!root)
            return 0;
        return root->val+sum(root->left)+sum(root->right);
    }
    int sumo(TreeNode* root, int& tot, long long int & ans){
        if(!root)
            return 0;
        int p =root->val+sumo(root->left, tot, ans)+sumo(root->right, tot, ans);
        ans=  max(ans, (tot-p)*1LL*(p));
        return p;
        
    }
    const int mod = 1e9+7;
    int maxProduct(TreeNode* root) {
        int tot = sum(root);
        long long int ans=0;
        int pp = sumo(root, tot, ans);
        return ans%mod;
    }
};