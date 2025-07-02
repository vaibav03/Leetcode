class Solution {
public:
    int longestSubsequence(string s, int k) {
        int val{},ans{},i,x = s.size()-32;
        for( i=s.size()-1;i>=max(x,0);i--){
            if(s[i]-'0'){
                if(val+pow(2,s.size()-1-i)>k) {
                    ans++;
                }else{
                    val+=pow(2,s.size()-1-i);
                }
            }
        }

        while(i>=0){
            if(s[i]-'0') ans++;
            i--;
        }
        return s.size() - ans;
    }
};