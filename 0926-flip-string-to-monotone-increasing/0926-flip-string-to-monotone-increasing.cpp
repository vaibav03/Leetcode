class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int pre{},tot{};
        for(int i=0;i<s.size();i++){
            if(s[i] == '0') tot++;
        }
        int ans = tot;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') pre++;
            int onesBef = i - pre +1, zeroesAft = tot - pre;
            ans = min(ans, onesBef + zeroesAft);  
        }
        return ans;
    }
};