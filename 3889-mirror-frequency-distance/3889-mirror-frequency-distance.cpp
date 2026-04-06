class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        int ans = 0;

        for (char c = '0'; c <= '9'; c++) {
            char mirror = '9' - (c - '0');
            if (c <= mirror) {
                ans += abs(freq[c] - freq[mirror]);
            }
        }

        for (char c = 'a'; c <= 'z'; c++) {
            char mirror = 'z' - (c - 'a');
            if (c <= mirror) {
                ans += abs(freq[c] - freq[mirror]);
            }
        }

        return ans;
    }
};