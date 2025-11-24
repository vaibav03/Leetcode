class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long maxSum = n*1ll*(n+1)/2;
        vector<int> ans;
        while(n){
            if(target + n > (n-1)*1ll*n/2 ){target-=n; ans.push_back(n);}
            else{ target+=n; ans.push_back(-n);}
            
            n--;
        }
        sort(ans.begin(),ans.end());
        if (target != 0) return {};
        return ans;
    }
};