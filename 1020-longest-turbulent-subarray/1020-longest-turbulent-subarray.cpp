class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;

        vector<int> up(n, 1), down(n, 1);
        int ans = 1;

        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = 1;
            } else if(arr[i] < arr[i-1]) {
                down[i] = up[i-1] + 1;
                up[i] = 1;
            } else {
                up[i] = down[i] = 1;
            }
            ans = max(ans, max(up[i], down[i]));
        }
        return ans;
    }
};
