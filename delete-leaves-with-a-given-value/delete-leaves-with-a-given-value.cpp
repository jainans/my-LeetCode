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
   
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL)
            return root;
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==target)
                return NULL;
            return root;
        }
        TreeNode* lef = removeLeafNodes(root->left, target);
        TreeNode* rit = removeLeafNodes(root->right, target);
        root->left=lef;
        root->right=rit;
        if(lef==NULL && rit==NULL && root->val==target)
            return NULL;
        return root;
    }
};