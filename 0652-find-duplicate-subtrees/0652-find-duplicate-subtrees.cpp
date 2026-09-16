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
unordered_map<string,int>m;
vector<TreeNode*>ans;
string ser(TreeNode* root){
    if(root == NULL){
        return "#";
    }
    string left = ser(root->left);
    string right = ser(root->right);
    string s = to_string(root->val) + "," + left + "," + right;
    m[s]++;
    if(m[s] == 2){
        ans.push_back(root);
    }
    return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        ser(root);
        return ans;
    }
};