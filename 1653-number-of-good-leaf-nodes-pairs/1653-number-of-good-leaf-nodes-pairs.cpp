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
 int ans{};
    vector<int> solve(TreeNode* root,int distance){
        if(root->left == NULL && root->right == NULL ) return {1};

        vector<int> right,left,res;

        if(root->right)
        right = solve(root->right, distance);

        if(root->left)
        left = solve(root->left,distance);


        for(int i=0;i<right.size();i++){
            for(int j=0;j<left.size();j++){
                if(right[i]+left[j] <= distance) {
                    ans++;
                }
            }
        }

        for(int i=0;i<right.size();i++){
            res.push_back(right[i]+1);
        }
        for(int i=0;i<left.size();i++){
            res.push_back(left[i]+1);
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        solve(root,distance);
        return ans;
    }
};