class Solution {
public:
    // Lower bound function to find the first index where nums[index] >= x
    int lb(vector<int>& nums, int x, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Use `lb` to find the range where nums[j] is within the range
            int leftBound = lb(nums, lower - nums[i], i + 1, nums.size() - 1);
            int rightBound = lb(nums, upper - nums[i] + 1, i + 1, nums.size() - 1);

            // Count valid pairs where j > i and nums[i] + nums[j] is within [lower, upper]
            ans += (rightBound - leftBound);
        }

        return ans;
    }
};
