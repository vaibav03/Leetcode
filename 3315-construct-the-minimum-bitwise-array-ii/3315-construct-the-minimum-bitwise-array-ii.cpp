class Solution {
public:
    int findAns(int n){
        int ans = n-1;
        for(int i=1;i<31;i++){
            if(n&(1<<i)){
                int x = (INT_MAX^(1<<i));
                
                int trial = (n&(x));
                cout<<n<<" "<<trial<<" "<<x<<endl;
                if((trial | (trial+1)) == n ) ans = min(ans , trial);
            }
        }
        return ans;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0) nums[i] = -1;
            else nums[i] = findAns(nums[i]);
        }
        return nums;
    }
};