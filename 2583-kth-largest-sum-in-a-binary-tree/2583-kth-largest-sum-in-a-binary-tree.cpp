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

    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<pair<TreeNode*,int>> q;
       q.push({root, 1});
        vector<long long> sums;
        while(!q.empty()){
            int size = q.size();
            long long sum{};
            for(int i=0;i<size;i++){
                auto x = q.front();
                q.pop();
                sum+= 1ll*x.first->val;
                if(x.first->left) q.push({x.first->left,x.second+1});
                if(x.first->right) q.push({x.first->right,x.second+1});
            }
            sums.push_back(sum);
        }
        if(sums.size() < k ) return -1;
        else {
            sort(sums.begin(),sums.end());
            return sums[sums.size() - k];
        }
    }
};