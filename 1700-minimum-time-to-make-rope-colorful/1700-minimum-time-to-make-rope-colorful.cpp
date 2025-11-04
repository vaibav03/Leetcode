class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int l{},r{},ans{};
        while(r<colors.size() && l<=r){
            int res = 0,maxi = 0; 
            while(r<colors.size() && colors[l] == colors[r]){
                 res+=time[r]; 
                 maxi = max(maxi,time[r]); 
                 r++; 
            }
            ans+=(res - maxi);
            l = r;
        }
        return ans;
    }
};