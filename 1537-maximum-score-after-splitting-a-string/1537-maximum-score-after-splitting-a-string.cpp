class Solution {
public:
    int maxScore(string s) {
        int num1{},num0{};
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') num1++;
        }
        int ans{};
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1') num1--;
            if(s[i]=='0') num0++;
            ans = max(ans,num0+num1);
        }
        return ans;
    }
};