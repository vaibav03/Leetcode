class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l{},r{},ans = 0;
       unordered_map<int,int> M;
       while(r< s.size()){
        M[s[r]]++;
        r++;
        while(M[s[r-1]] != 1){
            M[s[l]]--;
            l++;
            if(M[s[l]] == 0 ) M.erase(s[l]);
        }
        ans = max(ans, r-l);
       }
       return ans;
    }
};