class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if the current spot is empty and its adjacent spots are also empty
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                ans++;
                i++;
            }
        }
        
        return ans >= n;
    }
};
