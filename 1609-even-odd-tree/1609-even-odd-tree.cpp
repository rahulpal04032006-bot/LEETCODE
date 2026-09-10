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
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        queue<pair<TreeNode*,int>>q;
        vector<int>temp;
        q.push(make_pair(root,0));
        q.push({nullptr,0});
        while(!q.empty()){
            pair<TreeNode*,int>curr = q.front();
            q.pop();
            TreeNode* currNode = curr.first;
            int level = curr.second;
            if(currNode == nullptr){
               if (level % 2 == 0) {
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] % 2 == 0)
            return false;
        
        if (i > 0 && temp[i-1] >= temp[i])
            return false;
    }
}else {
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] % 2 != 0)
            return false;
        
        if (i > 0 && temp[i-1] <= temp[i])
            return false;
    }
}
                   temp.clear();
                    if(q.empty()){
                        break;
                    }
                    q.push({nullptr,level+1});
            }else{
                temp.push_back(currNode->val);
                if(currNode->left != nullptr){
                    pair<TreeNode* ,int> left = make_pair(currNode->left,level+1);
                    q.push(left);
                }
                    if(currNode->right != nullptr){
                    pair<TreeNode* ,int> right = make_pair(currNode->right,level+1);
                    q.push(right);
                }
            }
        }
        return true;
    }
};