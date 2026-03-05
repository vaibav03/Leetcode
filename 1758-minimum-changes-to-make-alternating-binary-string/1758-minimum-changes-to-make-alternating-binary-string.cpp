class Solution {
public:
    
    int minOperations(string s) {
        int z{},o{};
        for(int i=0;i<s.size();i++){
            if((i%2==0 && s[i]=='1') || (i%2 == 1 && s[i]=='0')) z++;
            if( (i%2==0 && s[i]=='0') || (i%2 == 1 && s[i]=='1') ) o++;
        }
        return min(o,z);
    }
};