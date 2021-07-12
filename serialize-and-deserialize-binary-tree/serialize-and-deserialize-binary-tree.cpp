/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
          return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos =0;
        return func(data, pos);
    }

    TreeNode* func(string & data, int& pos){
        if(pos<data.size() && data[pos]=='#')
        {
            pos+=2;
            return NULL;
            
        }
        int limi = data.find(',', pos);
        int len = limi-pos;
        int v = stoi(data.substr(pos, len));
        TreeNode* tt = new TreeNode(v);
        pos +=len+1;
        tt->left = func(data, pos);
        tt->right = func(data, pos);
        return tt;
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));