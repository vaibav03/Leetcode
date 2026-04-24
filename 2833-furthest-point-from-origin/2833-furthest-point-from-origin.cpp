class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l{},r{},dash{};
        for(auto x : moves){
            if(x=='L') l++;
            if(x=='R') r++;
            if(x=='_') dash++;
        }
        return abs(r-l) + dash; 
    }
};