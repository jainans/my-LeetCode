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
     unordered_map<TreeNode*, int>lef;
     unordered_map<TreeNode* , int>rit;
    
    int diameterOfBinaryTree(TreeNode* root) {
       if(root==NULL)
           return 0;
        if(root->left==NULL && root->right==NULL){
            lef[root]=0;
            rit[root]=0;
            return 0;
        }
        int p = 0;
        int q=0;
        int x = diameterOfBinaryTree(root->left);
        int y=  diameterOfBinaryTree(root->right);
        if(root->left)
            p = 1+max(lef[root->left], rit[root->left]);
        if(root->right)
            q = 1+max(lef[root->right], rit[root->right]);
        lef[root]=p;
        rit[root]=q;
        return max(p+q, max(x, y));
    }
};