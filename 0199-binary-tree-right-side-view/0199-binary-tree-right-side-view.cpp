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
vector<int>ans;
void level(pair<TreeNode*,int>root){
    if(root.first == NULL){
        return;
    }
    queue<pair<TreeNode*,int>>q;
    map<int,int>m;
    q.push(root);
    while(!q.empty()){
        pair<TreeNode*,int>curr = q.front();
        q.pop();
        TreeNode*currNode = curr.first;
        int level = curr.second;
        m[level] = currNode->val;
        if(currNode->left != NULL){
            pair<TreeNode*,int>leftpair = make_pair(currNode->left,level+1);
            q.push(leftpair);
        }
        if(currNode->right != NULL){
            pair<TreeNode*,int>rightpair = make_pair(currNode->right,level+1);
            q.push(rightpair);
        }
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
}
    vector<int> rightSideView(TreeNode* root) {
        level(make_pair(root,1));
        return ans;
    }
};