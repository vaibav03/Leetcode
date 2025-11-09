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
    int cameras = 0;

    // returns: 0 = not covered, 1 = covered, 2 = has camera
    int dfs(TreeNode* root) {
        if(root->right==NULL && root->left==NULL) return 0;
        int right = 1,left = 1;
         
        if(root->right) right = dfs(root->right);
        if(root->left) left = dfs(root->left);


        if(right == 0 || left == 0){ cameras++; return 2;}

        else if(right == 2 || left == 2 ) return 1;
       
       return 0;
    }

    int minCameraCover(TreeNode* root) {
        //cout<<dfs(root)<<endl;
        if(root == NULL) return 0 ;
        if (dfs(root) == 0) {
            cameras++;
        }

        return cameras;
    }
};
