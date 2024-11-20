class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int a = 0, b = 0, c = 0;
        for (char ch : s) {
            if (ch == 'a') a++;
            else if (ch == 'b') b++;
            else if (ch == 'c') c++;
        }
        if (a < k || b < k || c < k) return -1;
        int l = 0, max_len = 0;
        int curr_a = 0, curr_b = 0, curr_c = 0;

        for (int r = 0; r < n; r++) {
            if (s[r] == 'a') curr_a++;
            else if (s[r] == 'b') curr_b++;
            else if (s[r] == 'c') curr_c++;

            while (curr_a > a - k || curr_b > b - k || curr_c > c - k) {
                if (s[l] == 'a') curr_a--;
                else if (s[l] == 'b') curr_b--;
                else if (s[l] == 'c') curr_c--;
                l++;
            }

            max_len = max(max_len, r - l + 1);
        }

        return n - max_len;
    }
};
