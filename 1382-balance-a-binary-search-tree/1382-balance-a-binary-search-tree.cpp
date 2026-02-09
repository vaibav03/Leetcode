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
    vector<TreeNode*> ans;
    TreeNode* curr ;
    void populate(TreeNode* root){
        if(!root) return ;
        ans.push_back(root);
        populate(root->right);
        populate(root->left);
    }
    TreeNode* balance( int l ,int r){
        if(l > r) return NULL;

        int mid = (l+r)/2;
        TreeNode* curr = ans[mid];
        curr->left = balance(l,mid-1);
        curr->right = balance(mid+1, r);
        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        populate(root);
        sort(ans.begin(),ans.end(),[](TreeNode* a,TreeNode* b){
            return a->val < b->val;
        });
        
        return balance(0,ans.size() - 1);
    }
};