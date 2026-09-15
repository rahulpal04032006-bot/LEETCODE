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
int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left , right) + 1;
}
void place(TreeNode* root,vector<vector<string>>& s,int col,int row,int x)
{
    if(root == NULL){
        return;
    }
    s[row][col] = to_string(root->val);
   if(row == x){
    return;
   }if(root->left)
    place(root->left,s,(col-(pow(2,x-row-1))),row+1,x);
    if(root->right)
    place(root->right,s,(col+(pow(2,x-row-1))),row+1,x);
    

}
    vector<vector<string>> printTree(TreeNode* root) {
       int x = height(root) - 1;
       int row = x + 1;
       int col = pow(2,x+1) - 1;
      vector<vector<string>> res(row, vector<string>(col, ""));
       place(root,res,(col-1)/2,0,x);
       return res;
    }
};