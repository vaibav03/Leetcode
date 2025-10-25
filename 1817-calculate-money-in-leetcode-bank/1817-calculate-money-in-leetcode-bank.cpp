class Solution {
public:
    int totalMoney(int n) {
        int quo = n/7, mod = n%7, ans{},numW = n/7;
         ans+= numW*28;
         ans+= max(((numW)*(numW-1)/2) * 7,0);

         for(int i=1;i<=n%7;i++) ans+= (i+numW);

         return ans;
    }
};