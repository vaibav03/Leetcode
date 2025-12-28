class Solution {
public:
    int minAllOneMultiple(int k) {
        long long i = 1;
        int movs = 1;
        if(k%2 == 0 || k%5 ==0) return -1;

        while(i%k != 0){
            i = (i*1ll*10 + 1) % k;
            movs++;
        }
       return movs;
    }
};