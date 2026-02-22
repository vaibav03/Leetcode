class Solution {
public:
    int fact(int n){
        if(n == 0) return 1;
        return n*fact(n-1);
    }
    bool isDigitorialPermutation(int n) {
        long long ans{};
        int dup = n;
        vector<int> hash(10,0);
        while(n){
            int num = n%10;
            ans = ans + 1ll*fact(num);
            hash[num]++;
            n/=10;
        }

        while(ans){
            int num = ans%10;
            hash[num]--;
            ans/=10;
        }
        for(auto x : hash){
            if(x!=0) return false; 
        }
        return true;
    }
};