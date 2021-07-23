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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode* lef = pruneTree(root->left);
        TreeNode* rit = pruneTree(root->right);
        if(!lef && !rit){
            if(root->val==0)
                return NULL;
            else
            {
                root->left=NULL;
                root->right=NULL;
                return root;
            }
        }
        if(lef==NULL)
            root->left=NULL;
        if(rit==NULL)
            root->right=NULL;
        return root;
        
    }
};