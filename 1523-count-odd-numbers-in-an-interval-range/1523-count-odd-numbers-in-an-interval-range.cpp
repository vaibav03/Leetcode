class Solution {
public:
    int countOdds(int low, int high) {
        if (low == high) return(low%2 == 1); 
        int ans{};
        if(low%2 == 1){ low++; ans++;}
        if(high%2 == 1) {high--;    ans++; }

        ans+= (max(high - low,0)/2 );
        return ans;
    }
};