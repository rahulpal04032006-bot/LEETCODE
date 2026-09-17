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
map<int,vector<int>>m;
TreeNode* lca(TreeNode* root,int m,int n){
    if(root == NULL){
        return NULL;
    }
    if(root->val == m || root->val == n){
        return root;
    }
    TreeNode* left = lca(root->left,m,n);
    TreeNode* right = lca(root->right,m,n);
    if(left != NULL && right != NULL)
    return root;
    return left == NULL?right:left;
}
void level(TreeNode* root,int i){
    if(root == NULL){
        return;
    }
    m[i].push_back(root->val);
    level(root->left,i+1);
    level(root->right,i+1);
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        level(root,0);
        auto last = m.rbegin();
        vector<int>v = last->second;
        if(v.size() == 1){
            return lca(root,v[0],v[0]);
        }
        TreeNode* ans = lca(root,v[0],v[1]);
        for(int i=2;i<v.size();i++){
            ans = lca(root,ans->val,v[i]);
        }
        return ans;
    }
};