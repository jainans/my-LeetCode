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
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* fst = NULL;
    TreeNode* sec = NULL;
    
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        if(fst==NULL && root->val<prev->val){
            fst=prev;
        }
         if(fst!=NULL && root->val<prev->val){
            sec=root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
     inorder(root);
        int temp = sec->val;
        sec->val = fst->val;
        fst->val =temp;
    }
};