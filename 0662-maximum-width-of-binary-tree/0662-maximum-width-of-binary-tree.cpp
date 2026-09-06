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
long long ans = 0;
void level(TreeNode* root){
    if(root ==  NULL){
        return ;
    }
    queue<pair<TreeNode*,long long>>q;
    q.push(make_pair(root,0)); 
    while(!q.empty()){
         long long firstidx = q.front().second;
    long long lastidx = firstidx;
        pair<TreeNode*,int>curr = q.front();
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* currNode = q.front().first;
            long long idx = q.front().second;
            q.pop();
            idx = idx - firstidx;
            lastidx = idx;
            if(currNode->left != NULL){
                q.push({currNode->left,2*idx + 1});
            }
            if(currNode->right != NULL){
                q.push({currNode->right,2*idx + 2});
            }
        }
        ans = max(ans,lastidx + 1);
    }
   
}
    int widthOfBinaryTree(TreeNode* root) {
        level(root);
        return (int)ans;
    }
};