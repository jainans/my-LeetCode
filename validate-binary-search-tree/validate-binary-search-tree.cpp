class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return true;
       bool b = isValidBST(root->left);
        if(!b)
            return false;
        bool c = isValidBST(root->right);
        if(!c)
            return false;
        TreeNode* lef = root->left;
        if(lef!=NULL){
        while(lef->right!=NULL)
            lef = lef->right;
        
        if(lef->val>=root->val)
            return false;
        }
        TreeNode* rit = root->right;
        if(rit!=NULL){
            while(rit->left!=NULL)
                rit  = rit->left;
            if(rit->val<=root->val)
                return false;
        }
        return true;
    }
};