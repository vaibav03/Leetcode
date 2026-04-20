class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        int i =0 , n = colors.size();
        while(i<n && colors[i] == colors[n-1]) i++;

        ans = max(ans, n - i-1);
        i = n-1;
        while(i>=0 && colors[i] == colors[0]) i--;
        ans = max(ans,  i);
        return ans;
    }
};