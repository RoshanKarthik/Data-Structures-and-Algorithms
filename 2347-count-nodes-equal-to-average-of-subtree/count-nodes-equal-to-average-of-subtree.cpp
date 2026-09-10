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
using pii = pair<int,int>;
class Solution {
private:
    int count = 0;
    pii dfs(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        pii left = dfs(root->left);
        pii right = dfs(root->right);

        int nodeSum = left.first + right.first + root->val;
        int nodeCount = left.second + right.second + 1;

        if(root->val == (nodeSum/nodeCount)) count++;

        return {nodeSum,nodeCount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};