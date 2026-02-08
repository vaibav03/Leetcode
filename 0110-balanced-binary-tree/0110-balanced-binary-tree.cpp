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
    bool ans = true;
    int rec(TreeNode* root){
        if(!root) return 0;

        int left = 1 + rec(root->left), right = 1 + rec(root->right);
        
        if(abs(left - right) > 1 ) ans = false;

        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        rec(root);
        return ans;
    }
};