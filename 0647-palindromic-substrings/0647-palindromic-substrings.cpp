class Solution {

public:
   // vector<int> vis()
    int rec(string s, int ind){
        int l = ind , r = ind ;
        int ans{};
        while(l>=0 && r <s.size() && s[l]==s[r]){
            l--;
            r++;
            ans++;
        }
            l = ind - 1, r = ind;
            while(l>=0 && r <s.size() && s[l]==s[r]){
            l--;
            r++;
            ans++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int n = s.size(),ans{};
        for(int ct = 0;ct<s.size();ct++){
            ans+= rec(s,ct);
        }
        return ans;
    }
};