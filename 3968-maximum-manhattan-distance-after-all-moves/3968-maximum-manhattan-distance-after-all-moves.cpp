class Solution {
public:
    int maxDistance(string moves) {
        int dash{}, side{}, updown{};
        for(auto x : moves){
            if(x == 'L'){
                side++;
            }else if(x == 'R'){
                side--;
            }else if(x == 'U'){
                updown++;
            }else if(x == 'D'){
                updown--;
            }else{
                dash++;
            }
        }
        return abs(side) + abs(updown) + dash;
    }
};