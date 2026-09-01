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
int kthlevel(TreeNode* root,int currlevel){
    if(root == NULL){
        return 0;
    }
    queue<pair<TreeNode*,int>>q;
    q.push(make_pair(root,currlevel));
    map<int,int>m;
    while(!q.empty()){
        pair<TreeNode*,int>curr = q.front();
        q.pop();
        TreeNode* currNode = curr.first;
        int level = curr.second;
        m[level] += currNode->val;
        if(currNode->left != NULL){
            pair<TreeNode*,int>leftpair = make_pair(currNode->left,level+1);
            q.push(leftpair);
        }
        if(currNode->right != NULL){
            pair<TreeNode*,int>rightpair = make_pair(currNode->right,level+1);
            q.push(rightpair);
        }
    }
    int max1 = INT_MIN;
    int x = currlevel;
    for(auto i:m){
        if(i.second > max1){
            max1 = i.second;
            x = i.first;
        }
    }
    return x;
}
    int maxLevelSum(TreeNode* root) {
        return kthlevel(root,1);
    }
};