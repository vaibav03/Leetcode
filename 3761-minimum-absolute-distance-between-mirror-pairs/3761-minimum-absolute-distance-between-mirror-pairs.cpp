class Solution {
public:
    int reverse(int n){
        int rev{},tot_pow{},powe{};
        int dupe = n;
        while(dupe){
            dupe/=10;
            tot_pow++;
        }
        

        while(n){
            rev+=(pow(10,tot_pow - powe-1)*(n%10));
            powe++;
            n/=10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> hash;
        int ans = INT_MAX;

        for(int i=0;i<nums.size();i++){
            int rev = reverse(nums[i]);

            if(hash.count(nums[i]))
            ans = min(ans, i - hash[nums[i]]);

            hash[rev] = i;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};