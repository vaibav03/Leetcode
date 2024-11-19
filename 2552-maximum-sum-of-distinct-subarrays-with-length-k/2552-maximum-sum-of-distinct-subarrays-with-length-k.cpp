class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return 0; 

        long long sum = 0, ans = 0;
        map<int, int> M; 

        for (int i = 0; i < k; i++) {
            M[nums[i]]++;
            sum += nums[i];
        }

        if (M.size() == k) ans = max(ans, sum);

        for (int i = k; i < n; i++) {
            sum -= nums[i - k];
            M[nums[i - k]]--;
            if (M[nums[i - k]] == 0) M.erase(nums[i - k]);

            sum += nums[i];
            M[nums[i]]++;

            if (M.size() == k) ans = max(ans, sum);
        }

        return ans;
    }
};
