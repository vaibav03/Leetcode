class Solution {
public:
    int differenceOfSums(int n, int m) {
        int div{},notdiv{};
        for(int i=1;i<=n;i++){
            if(i%m) notdiv+=i;
            else div+=i;
        }
        return notdiv-div;
    }
};