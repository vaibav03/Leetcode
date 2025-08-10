class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans {};
        vector<int> vis(fruits.size(),0);
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<fruits.size();j++){
                if(!vis[j] && baskets[j]>=fruits[i]) {
                    ans++; 
                    vis[j] = 1;
                    break;
                }
            }
        }
        return fruits.size() - ans;

    }
};