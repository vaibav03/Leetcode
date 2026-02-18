class Solution {
public:
    bool hasAlternatingBits(int n) {
        int maxSet = 0,i{};
        while(i <= 31){
            if( n&(1<<i)) maxSet = i;

            i++;
        }
        i= 0;
        while(i <= maxSet){
            bool x = n&(1<<i);
            bool y = n&(1<<(i+1));
            i++;
            if(x==y) return false; 
        }
        return true;
    }
};