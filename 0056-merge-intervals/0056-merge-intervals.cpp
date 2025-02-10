class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i{},j=0;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        while(j<=intervals.size()){
            if(j!=intervals.size() && intervals[i][1]>=intervals[j][0])
            {
                intervals[i][1] = max(intervals[i][1],intervals[j][1]);
                j++;
            }
            else{
                ans.push_back({intervals[i][0],max(intervals[j-1][1],intervals[i][1])});
                i=j;
                j++;
            }
        }
        return ans;
    }
};