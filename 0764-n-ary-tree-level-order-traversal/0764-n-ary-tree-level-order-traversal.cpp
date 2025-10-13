/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        queue<pair<int,Node *>> q;
        vector<vector<int>> ans;
        q.push({0,root});
        while(!q.empty()){
            auto [lev,_] = q.front();
            vector<int> v;
            while(lev == q.front().first){
            int lev  = q.front().first;
            Node * node = q.front().second;
            q.pop();
            v.push_back(node->val);
            for( auto neigh : node->children){
                q.push({lev+1,neigh});
            }
            }
            ans.push_back(v);
        }
        return ans;
    }
};