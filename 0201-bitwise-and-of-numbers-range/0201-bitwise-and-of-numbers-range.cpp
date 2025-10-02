class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int diff = right - left;
        int ans = (right & left);
        
        for (int i = 31; i >= 0; i--) {
            if (diff & (1 << i)) {
                unsigned mask = ~((1u << (i+1)) - 1);  
                ans &= mask;
                break;
            }
        }
        return ans;
    }
};
