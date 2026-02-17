class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<int,int> M;
       int l{},r{},ans = 0;
       while(r< s.size()){
        M[s[r]]++;
        r++;
        while(M.size() < r-l){
            M[s[l]]--;
            if(M[s[l]] == 0) M.erase(s[l]);
            l++;
        }

       // cout<<l<<" "<<r<<endl;
        ans = max(ans ,r-l);
       }
    return ans;
    }
};