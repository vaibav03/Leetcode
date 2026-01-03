class Solution {
public:
    int hammingWeight(int n) {
        int ans{};
        for(int i=0;i<=31;i++){
            if(n&(1<<i)) ans++;
    }
        return ans;
    }
};