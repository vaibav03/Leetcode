class Solution {
public:
    int minSwaps(string s) {
        int maxi{},close{};
        for(int i=0;i<s.size();i++){
            if(s[i] == '[') close--;
            else close ++;

            maxi = max(close,maxi);
        }
        return (maxi+1)/2;
    }
};