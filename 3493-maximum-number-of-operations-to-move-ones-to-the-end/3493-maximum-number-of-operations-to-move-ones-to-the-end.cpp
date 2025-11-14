class Solution {
public:
    int maxOperations(string s) {
        int ans{},cont{};
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == '1' && s[i+1]=='0'){ cont++; ans+=cont;}
            else if(s[i]=='1' && s[i+1]=='1') cont++;
        }
        return ans;
    }
};