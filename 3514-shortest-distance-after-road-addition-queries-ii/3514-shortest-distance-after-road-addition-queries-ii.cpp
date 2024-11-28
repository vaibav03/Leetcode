class Solution {
public:  
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        vector<int> ans;
        for (auto& query : queries) {
            int l = query[0], r = query[1];
            auto start = s.lower_bound(l+1);
            auto end = s.upper_bound(r-1);
            s.erase(start, end);
            ans.push_back(s.size()-1);
        }

        return ans;

        }
};