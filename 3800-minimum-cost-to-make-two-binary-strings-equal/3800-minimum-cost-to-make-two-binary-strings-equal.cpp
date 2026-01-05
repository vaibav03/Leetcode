class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n1{},n0{};
        for(int i=0;i<s.size();i++){
            if(s[i] != t[i] && s[i]=='1') n1++;
            else if(s[i] != t[i] && s[i]=='0') n0++;
        }
        int ans = 1e9;
        long long c1 = (n0+n1) *1ll* flipCost;
        long long c2 = min(n0,n1)*1ll*swapCost + (max(n0,n1)- min(n0,n1)) *1ll* flipCost; 
        long long c3;
        if( (n0 - n1) %2 == 0)
        c3 = (max(n0,n1) - min(n0,n1)) *1ll*  crossCost/2 + (n1+n0)*1ll*swapCost/2;
        else 
        c3 = ((max(n0,n1) - min(n0,n1))/2 *1ll* crossCost + (n1+n0)/2*1ll*swapCost) + flipCost;

        return min({c1,c2,c3});
    }
};