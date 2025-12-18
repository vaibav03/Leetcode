class Solution {
public:
    int countTriples(int n) {
        int ans{};
        for(int a=1;a<=n;a++){
            for(int b = 1;b<=n;b++){
                int c_sq = a*a + b*b,c = sqrt(c_sq);
                if( c_sq == c*c && sqrt(c_sq) <= n ){ 
                    ans++;}
            }
        }
        return ans;
    }
};