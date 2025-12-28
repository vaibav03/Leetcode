class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<int> vis(k,0);
        long long i = 1;
        int movs = 1;

        while(i%k != 0){
            i = (i*1ll*10 + 1) % k;
            if(vis[i%k] == 1) return -1;
            vis[i%k] = 1;
            movs++;
        }
       return movs;

    }
};