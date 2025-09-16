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
    void reverse(vector<TreeNode*> &samelev){
        int n = samelev.size();
        for(int i=0;i<n;i++) cout<<samelev[i]->val<<" ";
        cout<<endl;

        for(int i=0;i<n/2;i++){
            int temp = samelev[i]->val;
            samelev[i]->val = samelev[n-i-1]->val;
            samelev[n-i-1]->val = temp;
        }

        for(int i=0;i<n;i++) cout<<samelev[i]->val<<" ";
        cout<<endl;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            auto x = q.front();
            int lev = x.second;
            vector<TreeNode*> samelev;
            while(!q.empty() && (q.front().second == lev) ){
                auto node = q.front();
                samelev.push_back(node.first);
                q.pop();
                if(node.first->left) q.push({node.first->left,node.second+1});
                if(node.first->right) q.push({node.first->right,node.second+1});
            }
            if(lev%2==1)
            reverse(samelev);
        }
        return root;
    }
};