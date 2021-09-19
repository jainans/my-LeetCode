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
    bool chk(TreeNode* root, TreeNode* subRoot){
         if(!root && !subRoot)
            return true;
        if(!root || !subRoot)
            return false;
        return ((root->val == subRoot->val) && (chk(root->left, subRoot->left) && chk(root->right, subRoot->right)));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
            return true;
        if(!root || !subRoot)
            return false;
        return (chk(root, subRoot) || (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)));
            
        
    }
};