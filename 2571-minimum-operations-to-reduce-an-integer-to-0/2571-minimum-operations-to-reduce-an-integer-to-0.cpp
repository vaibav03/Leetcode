class Solution {
public:
    int minOperations(int n) {
        if(n == 0 ) return 0;
         if(n == 1 || n == 2) return 1 ;
        int powe = log2(n);
        int val = pow(2,powe),ans{};
        if(val == n) return 1;
        return 1+ min(minOperations(2*val - n), minOperations(n - val));
    }
};