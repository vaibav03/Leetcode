/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;

        
       if(root == p || root==q) return root;

       TreeNode* right = NULL,*left = NULL;
       right = dfs(root->right,p,q);
       left = dfs(root->left,p,q);
       
       // if(root->val == 3) cout<<right->val<<" "<<left->val<<endl;

       if(right!=NULL && left!=NULL) return root;
       else return (right!=NULL) ? right : left;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};