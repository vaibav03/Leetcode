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
    int maxLevelSum(TreeNode* root) {
       queue<pair<TreeNode*,int>> q;
       q.push({root, 1});
        int maxi = INT_MIN, lev = -1;
        while(!q.empty()){
            int size = q.size(),curr_lev ;
            long long sum{};
            for(int i=0;i<size;i++){
                auto x = q.front();
                q.pop();
                sum+= x.first->val;
                if(x.first->left) q.push({x.first->left,x.second+1});
                if(x.first->right) q.push({x.first->right,x.second+1});
                curr_lev = x.second;
            }
            if(sum > maxi){
                maxi = sum;
                lev = curr_lev;
            }
        }
        return lev;
    }
};