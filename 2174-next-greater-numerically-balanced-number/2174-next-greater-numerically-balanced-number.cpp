class Solution {
public:
        bool isBalanced(int n) {
        int cnt[10] = {0};
        while (n) {
            cnt[n % 10]++;
            n /= 10;
        }
        for (int d = 0; d < 10; d++) {
            if (cnt[d] && cnt[d] != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int i = n+1;
        while(!isBalanced(i)){
            i++;
        }
        return i;
    }
};