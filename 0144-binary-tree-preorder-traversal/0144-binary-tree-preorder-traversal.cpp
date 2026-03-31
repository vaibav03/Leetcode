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
vector<int> nodes;
    void rec(TreeNode* root){
        if(root == NULL) return;
        nodes.push_back(root->val);
        rec(root->left);
        rec(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        rec(root);
        return nodes;
    }
};