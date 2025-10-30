class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        M[0] = 1; 
        
        int pre = 0, ans = 0;
        for(int x : nums) {
            pre += x;
            pre = ((pre % k) + k) % k;  
            ans += M[pre];
            M[pre]++;
        }
        return ans;
    }
};
