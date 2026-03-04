class Solution {
public:
    void invert(string &base){
        for(int i=0;i<base.size();i++){
            if(base[i] == '1') base[i] = '0';
            else base[i] = '1';
        }
    }
    void iteration(string &base){
        string rev = base;
        reverse(rev.begin(),rev.end());
        invert(rev);
        base = base + '1' + rev;
    }
    char findKthBit(int n, int k) {
       string base = "0";
       for(int i=0;i<n;i++){
        iteration(base);
       }
    return base[k-1];
    }
};