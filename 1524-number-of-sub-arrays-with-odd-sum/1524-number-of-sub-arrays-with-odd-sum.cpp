class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long eve = 1,odd{},ans{},pre{};
        int mod = 1e9 +7;
        for(int i=0;i<arr.size();i++){
            pre+= arr[i];
            if(pre%2 == 0){ eve++; ans =  (ans + odd)%mod;}
            else{ ans = (ans + eve)%mod; odd++;}
        }
        return ans;
    }
};