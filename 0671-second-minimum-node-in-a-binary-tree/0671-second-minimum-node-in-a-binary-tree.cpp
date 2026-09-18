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
map<int,int>m;
void inorder(TreeNode* root){
    if(root == NULL){
        return; 
    }
    inorder(root->left);
    m[root->val] = root->val;
    inorder(root->right);
}
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        if(m.size() < 2){
            return -1;
        }
       auto i = m.begin();
       i++;
       return i->first;
    }
};