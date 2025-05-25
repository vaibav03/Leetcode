class Solution {
public:
    long long minimumSteps(string s) {
        long long  num{},ans{};
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0') num++;

            if(s[i]=='1') ans+=num;
        }
        return ans;
    }
};