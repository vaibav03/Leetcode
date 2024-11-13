class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size(), 0);
        int j = 0, maxBeauty = 0;

        for (const auto& [queryPrice, queryIndex] : sortedQueries) {
            while (j < items.size() && items[j][0] <= queryPrice) {
                maxBeauty = max(maxBeauty, items[j][1]);
                j++;
            }
            result[queryIndex] = maxBeauty;
        }

        return result;
    }
};
