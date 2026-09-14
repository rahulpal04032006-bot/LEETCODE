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
TreeNode* lca1(TreeNode* root,int x,int y){
    if(root == NULL){
        return NULL;
    }
    if(root->val == x || root->val == y){
        return root;
    }
    TreeNode* left = lca1(root->left,x,y);
    TreeNode* right = lca1(root->right,x,y);
    if(left != NULL && right != NULL){
        return root;
    }
    return left == NULL?right:left;

}
void lca(TreeNode* root,int i){
    if(root == NULL){
        return;
    }
    m[i].push_back(root->val);
    lca(root->left,i+1);
    lca(root->right,i+1);
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        lca(root,0);
        auto last = m.rbegin();
        vector<int>vec = last->second;
        if(vec.size() == 1){
            return lca1(root,vec[0],vec[0]);
        }
        TreeNode* ans = lca1(root,vec[0],vec[1]);
        for(int i=2;i<vec.size();i++){
            ans = lca1(root,ans->val,vec[i]);
        }
    return ans;
    }
};