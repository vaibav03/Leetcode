
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true; 
        if (root1 == nullptr || root2 == nullptr)
            return false;
        if (root1->val != root2->val)
            return false; 

        queue<pair<TreeNode*, TreeNode*>> q1, q2;
        q1.push({root1, nullptr});
        q2.push({root2, nullptr});

        while (!q1.empty() && !q2.empty()) {
            vector<pair<TreeNode*, TreeNode*>> v1, v2;

            while (!q1.empty() && !q2.empty()) {
                auto x = q1.front(); q1.pop();
                auto y = q2.front(); q2.pop();

                v1.push_back(x);
                v2.push_back(y);
            }

            if (v1.size() != v2.size())
                return false;

            for (int i = 0; i < v1.size(); i++) {
                TreeNode* node1 = v1[i].first;
                TreeNode* node2 = v2[i].first;

                TreeNode* left1 = node1->left;
                TreeNode* right1 = node1->right;
                TreeNode* left2 = node2->left;
                TreeNode* right2 = node2->right;

                bool normalOrder = (areNodesEqual(left1, left2) && areNodesEqual(right1, right2));
                bool flippedOrder = (areNodesEqual(left1, right2) && areNodesEqual(right1, left2));

                if (!normalOrder && !flippedOrder)
                    return false;

                if (normalOrder) {
                    if (left1) q1.push({left1, node1});
                    if (right1) q1.push({right1, node1});
                    if (left2) q2.push({left2, node2});
                    if (right2) q2.push({right2, node2});
                } else { 
                    if (left1) q1.push({left1, node1});
                    if (right1) q1.push({right1, node1});
                    if (right2) q2.push({right2, node2});
                    if (left2) q2.push({left2, node2});
                }
            }
        }
        return q1.empty() && q2.empty(); 
    }

private:
    bool areNodesEqual(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 == nullptr || node2 == nullptr) return false;
        return node1->val == node2->val;
    }
};
