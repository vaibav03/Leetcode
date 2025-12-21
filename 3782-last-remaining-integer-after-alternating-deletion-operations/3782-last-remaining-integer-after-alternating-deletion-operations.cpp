class Solution {
public:
    long long lastInteger(long long n) {
        long long len = n, d = 1, a = 1;
        long long mov = true; // tr - left, fals - right
        while(len > 1){
            if(!mov && len%2 == 0) a +=d; 
            len = ceil(len/2.0);
            d = 2*d;
            mov = !mov;
        }
        return a;
    }
};