#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, pair<int, int>> M; 
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (M.find(s[i]) == M.end()) {
                M[s[i]] = {i, i}; 
            } else {
                M[s[i]].second = i; 
            }
        }

        for (auto& [ch, indices] : M) {
            int start = indices.first, end = indices.second;
            if (start < end) {
                unordered_set<char> unique;
                for (int j = start + 1; j < end; j++) {
                    unique.insert(s[j]);
                }
                ans += unique.size();
            }
        }

        return ans;
    }
};
