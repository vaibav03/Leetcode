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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        else if(!root) return NULL;

        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        TreeNode* left = lowestCommonAncestor(root->left,p,q);

        cout<<right<<" "<<left<<endl;
        if(right!=NULL && left!=NULL){return root;}
        else if(right!=NULL){return right;}
        else{return left;}
    }
};