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
    private:
    TreeNode*helper(string data, int& idx){
        string ans;
        while(idx < data.size() && data[idx] != ','){
            ans += data[idx];
            idx++;
        }
        if(idx < data.size()){
            idx++;
        }
        if(ans == "#"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(ans));
        root->left = helper(data,idx);
        root->right = helper(data,idx);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if(root == NULL){
        return "#";
      }
      return to_string(root->val) + "," + serialize(root->left) +"," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
   
    TreeNode* deserialize(string data) {
        int idx = 0;
        return helper(data,idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;