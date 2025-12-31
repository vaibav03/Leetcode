class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size(),xy{},yx{};
        for(int i=0;i<n;i++){
            if(s1[i] == 'x' && s2[i]=='y') xy++;
            else if(s1[i] == 'y' && s2[i]=='x') yx++;
        }
        if(xy%2 != yx%2) return -1;
        return ceil(xy/2.0) + ceil(yx/2.0) ; 
    }
};