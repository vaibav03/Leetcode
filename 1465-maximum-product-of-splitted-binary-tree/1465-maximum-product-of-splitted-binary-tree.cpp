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
    long long sum{}, sub{},MOD = 1e9 + 7,ans{};
    void dfs(TreeNode * root){
        if(root == NULL) return ;

        
        dfs(root->left);
        dfs(root->right);
        sum+= (root->val);        
    }
    long long dfss(TreeNode * root){
        if(root == NULL) return 0;
        long long left = dfss(root->left);
        long long right = dfss(root->right);
        long long subtree_sum = (left+right+root->val)%MOD;
        long long curr = ((sum - subtree_sum) * (subtree_sum));
        ans = max(curr,ans);
        return subtree_sum;
    }

    int maxProduct(TreeNode* root) {
        dfs(root);
        dfss(root);
        return ans%MOD;
    }
};