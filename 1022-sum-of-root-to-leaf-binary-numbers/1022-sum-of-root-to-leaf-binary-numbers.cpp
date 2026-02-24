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
    vector<string> bins;
    void getallBins(TreeNode* root,string &pres){
        if(root->val == 1) pres+='1';
        else pres+='0';

        if( root->left == NULL && root->right == NULL ){ bins.push_back(pres); }

        if(root->left)
         getallBins(root->left, pres);
         if(root->right)
         getallBins(root->right,pres);

         pres.pop_back();
    }
    int converttoInt(string s){
        int powe = s.size()-1,i{};
        int ans{};
        while(i<s.size()){
            if(s[i] == '1')
            ans+= pow(2,powe);

            powe--;
            i++;
        }
        return ans;
    }

    int sumRootToLeaf(TreeNode* root) {
        string empty = "";
        getallBins(root,empty);
        int ans{};
        for(auto x : bins){
            ans+= converttoInt(x);
            cout<<x<<" "<<converttoInt(x)<<endl;
        }
        return ans;
    }
};