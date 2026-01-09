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
unordered_map<TreeNode* , int> depth;
 void findDepth(TreeNode* root,int d){
    if(root == NULL) return ;

    depth[root] = d;
    findDepth(root->right,d+1);
    findDepth(root->left,d+1);
 }
    TreeNode* lca(TreeNode* root ,TreeNode* p,TreeNode* q){
        if( root == NULL )return NULL;
        if(root == p || root == q )return root;

        TreeNode* right = lca(root->right, p , q);
        TreeNode* left = lca(root->left , p , q);

        if(right && left) return root;
        else if(right) return right;
        else return left;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> nodes;
        findDepth(root , 0);
        int maxi = -1;
        for(auto x : depth){
            maxi = max(maxi,x.second);
        }
        for(auto x : depth){
            if(x.second == maxi) nodes.push_back(x.first);
        }

        TreeNode* ans;

        if(nodes.size() >=2)
         ans = lca(root,nodes[0],nodes[1]);
        else return nodes[0];

        for(int i=2;i<nodes.size();i++){
            ans = lca(root, ans,nodes[i]);
        }
        if(ans!=NULL)
        cout<<ans->val<<endl;

        return ans;
    }
};