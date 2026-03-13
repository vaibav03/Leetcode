class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& workerTimes) {

        long long lo = 0, hi = 1e16;
        long long ans = hi;

        while (lo <= hi) {

            long long mid = lo + (hi - lo) / 2;
            long long total = 0;

            for (int t : workerTimes) {

                long double work = (long double)mid / t;

                long long k = (long long)(-0.5 + sqrt(0.25 + 2 * work));

                total += k;

                if (total >= h) break;
            }

            if (total >= h) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};