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
    map<pair<TreeNode*, int> , int >mpnot;
    map<pair<TreeNode*, int> , int >mpyes;
    int solve(TreeNode* root, int trg, int flag){
        if(!root)
            return 0;
        if(root->left==NULL && root->right==NULL){
            if(flag==1){
                if(root->val==trg)
                    return mpyes[{root, trg}]=1;
                else
                    return mpyes[{root, trg}]=0;
            }
            else{
                return mpnot[{root, trg}]=0;
            }
        }
        if(flag==1){
            if(mpyes.find({root, trg})!=mpyes.end())
                return mpyes[{root, trg}];
            mpyes[{root, trg}]=0;
            mpyes[{root, trg}]+=solve(root->left, trg-root->val, 1)+solve(root->right, trg-root->val, 1);
            if(root->val==trg)
                mpyes[{root, trg}]+=1;
            return mpyes[{root, trg}];
        }
        else{
            if(mpnot.find({root, trg})!=mpnot.end())
                return mpnot[{root, trg}];
            mpnot[{root, trg}]=0;
            mpnot[{root, trg}]+=solve(root->left, trg, 1)+solve(root->left, trg, 0)+solve(root->right, trg, 1)+solve(root->right, trg, 0);
            return mpnot[{root, trg}];
        }
            
    }
    int pathSum(TreeNode* root, int targetSum) {
       int ans = solve(root, targetSum, 0)+solve(root, targetSum, 1);
        return ans;
    }
};