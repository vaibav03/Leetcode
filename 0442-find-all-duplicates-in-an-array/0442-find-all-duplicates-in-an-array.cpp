class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            while( nums[i]!=i+1){
                int ind1 = nums[i]-1, ind2 = i;
                cout<<ind1<<" "<<ind2<<endl;
                if(nums[ind1] == nums[ind2]){ s.insert(nums[ind1]); break;}
                else{
                    int temp = nums[ind1];
                    nums[ind1] = nums[ind2];
                    nums[ind2] = temp;
                }
            }
            cout<<i<<" ";
        }
        vector<int> ans(s.begin(),s.end());
        return ans;
    }
};