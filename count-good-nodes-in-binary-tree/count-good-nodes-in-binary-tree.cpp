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
    int goodNodes(TreeNode* root, int p = INT_MIN) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL){
            if(p>root->val)
                return 0;
            return 1;
        }
        if(root->val>=p){
            return 1+goodNodes(root->left, root->val)+goodNodes(root->right, root->val);
        }
        return goodNodes(root->left, p)+goodNodes(root->right, p);
            
    }
};