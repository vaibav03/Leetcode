#include <vector>
#include <stack>

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        std::vector<int> nseVec = nse(arr);
        std::vector<int> pseVec = pse(arr);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pseVec[i];
            long long right = nseVec[i] - i;
            total = (total + arr[i] * left % mod * right % mod) % mod;
        }

        return total;
    }

private:
    std::vector<int> nse(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> nseVec(n, n);
        std::stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                nseVec[i] = st.top();
            }
            st.push(i);
        }

        return nseVec;
    }

    std::vector<int> pse(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> pseVec(n, -1);
        std::stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                pseVec[i] = st.top();
            }
            st.push(i);
        }

        return pseVec;
    }
};
