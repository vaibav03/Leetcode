class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int mini = INT_MAX;
        int neg = 0;

        for (auto& row : matrix) {
            for (int val : row) {
                totalSum += abs(val);
                if (val < 0) {
                    neg++;
                }
                mini = min(mini, abs(val));
            }
        }

        if (neg % 2 == 1) {
            totalSum -= 2 * mini;
        }

        return totalSum;
    }
};