class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int num_a{},n = s.size();
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a') num_a++;
        }
        return abs(n - 2*num_a);
    }
};