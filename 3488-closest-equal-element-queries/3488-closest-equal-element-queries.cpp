class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        map<int,vector<int>> mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }

        int N = nums.size();

        for(auto q : queries){
            auto &vec = mpp[nums[q]];
            int k = vec.size();

            if(k == 1) {
                ans.push_back(-1);
            } else {
                int ind = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

                int curr_ind = vec[ind];
                int prev = vec[(ind - 1 + k) % k];
                int next = vec[(ind + 1) % k];

                int d1 = abs(curr_ind - prev);
                d1 = min(d1, N - d1);

                int d2 = abs(next - curr_ind);
                d2 = min(d2, N - d2);

                ans.push_back(min(d1, d2));
            }
        }
        return ans;
    }
};