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
    unordered_map<TreeNode*, long long> dp;
    int findSum(TreeNode * root){
        if(root == NULL) return 0;
        return dp[root] = root->val + findSum(root->right) + findSum(root->left);
    }

    
    int maxProduct(TreeNode* root) {
        long long sum {},ans = 1;
        int mod = 1e9 +7;
        sum = findSum(root);
        for(auto x : dp){
            ans = max(ans, x.second*1ll*(sum - x.second));
        }
        
        return ans%mod;
    }
};