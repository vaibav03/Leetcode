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
    int ans(TreeNode* root, int &k){
        if(!root) return 0;

        int left = ans(root->left,k);
        k--;
        
        if(k==0) return root->val;

        int right = ans(root->right,k);
        int ret = 0;
        if(right !=0) ret = right;
        if(left!=0) ret = left;

        return ret;
    }
    int kthSmallest(TreeNode* root, int k) {
        return ans(root,k);
    }
};