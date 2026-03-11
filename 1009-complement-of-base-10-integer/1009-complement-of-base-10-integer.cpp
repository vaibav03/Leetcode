class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        string s = "";
        int i{};
        while(n){
            if(n&1) s+='1';
            else s+='0';
            n>>=1;
        }
        cout<<s<<endl;
        int ans{};
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == '0') ans+= pow(2,i);
        }
        return ans;
    }
};