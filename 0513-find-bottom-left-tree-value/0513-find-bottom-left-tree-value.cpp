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
int level(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    queue<pair<TreeNode*,int>>q;
    map<int,int>m;
    q.push(make_pair(root,1));
    while(!q.empty()){
        pair<TreeNode*,int>curr = q.front();
        q.pop();
        TreeNode* currNode = curr.first;
        int level = curr.second;
        if(m.count(level) == 0){
            m[level] = currNode->val;   
        }
        if(currNode->left != NULL){
            pair<TreeNode*,int>leftpair = make_pair(currNode->left,level+1);
            q.push(leftpair);
        }
        if(currNode->right != NULL){
            pair<TreeNode*,int>rightpair = make_pair(currNode->right,level+1);
            q.push(rightpair);
        }
    }
    vector<int>ans;
    for(auto i: m){
        ans.push_back(i.second);
    }
    int x = ans[ans.size()-1];
    return x;
}
    int findBottomLeftValue(TreeNode* root) {
       return level(root);
      
    }
};