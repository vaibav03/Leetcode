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
    int rob(TreeNode* root) {
         unordered_map<TreeNode *,int> M;
         return f(root,M);
    }
    int f(TreeNode* root, unordered_map<TreeNode *,int> &M){
        if(!root)
        return 0;

        if(M.find(root)!=M.end())
        return M[root];

           int maxtake = root->val;
           if(root->right)
           maxtake+=f(root->right->left,M)+f(root->right->right,M);
           if(root->left)
           maxtake+=f(root->left->left,M)+f(root->left->right,M);

          int nottake = f(root->right,M) + f(root->left,M);

            return M[root] = max(maxtake,nottake);

    }
};