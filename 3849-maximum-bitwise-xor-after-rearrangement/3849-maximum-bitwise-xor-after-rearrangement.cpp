class Solution {
public:
    string maximumXor(string s, string t) {
        int num0{},num1{};
        for(auto x : t){
            if(x == '0') num0++;
            else num1++;
        }
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == '1'){
                if(num0>0){
                    ans+='1';
                    num0--;
                }else{
                    ans+='0';
                }
            } else{
                if(num1>0){
                    ans+='1';
                    num1--;
                }else{
                    ans+='0';
                }
            }
        }
        return ans;
    }
};