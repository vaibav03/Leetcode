class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i{};
        while(i<n){
            int start = intervals[i][0], end = intervals[i][1];
            while(i<intervals.size() && end >= intervals[i][0]){ 
                end = max(end, intervals[i][1]);
                i++;
            }
            
        ans.push_back({start,end});
        }
       return ans;
    }
};