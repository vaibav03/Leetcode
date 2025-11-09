class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        map<char,int> freq;
        for (auto &w : words)
            for (auto c : w)
                freq[c]++;

        int totalPairs = 0;
        for (auto &[ch, cnt] : freq)
            totalPairs += cnt / 2;

        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        int ans = 0;
        for (auto &w : words) {
            int needPairs = w.size() / 2;
            if (totalPairs >= needPairs) {
                totalPairs -= needPairs;
                ans++;
            } else {
                break;
            }
        }

        return ans;
    }
};
