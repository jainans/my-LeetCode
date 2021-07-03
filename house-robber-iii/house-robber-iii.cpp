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
    unordered_map<TreeNode*, int >mpy;
    unordered_map<TreeNode*, int>mpn;
    int robs(TreeNode* root, int flag){
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL){
            if(flag==1)
           return mpy[root]=root->val;
           return mpn[root] = 0;
        }
        if(flag==1 && mpy.find(root)!=mpy.end())
            return mpy[root];
        if(flag==0 && mpn.find(root)!=mpn.end())
            return mpn[root];
        if(flag==1){
            return mpy[root]=root->val+robs(root->left, 0)+robs(root->right, 0);
        }
        
            return mpn[root] = max(robs(root->left, 0), robs(root->left, 1))+max(robs(root->right, 0), robs(root->right, 1));
        
    }
    int rob(TreeNode* root) {
        int p = robs(root, 0);
        int q = robs(root, 1);
        return max(p, q);
    }
};