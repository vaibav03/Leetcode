class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int num0{},ans{};
        map<int,int> M;
        M[0] = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) num0++;
            cout<<i<<" "<<num0<<endl;
            if(M.find(i-2*num0+1) == M.end()){
                M[i-2*num0+1] = i;
            }else{
                ans = max(ans, i - M[i-2*num0+1]);
            }
        }
        return ans;
    }
};