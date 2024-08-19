class Solution {
public:
    int nthUglyNumber(int n) {
     vector<int> dp;
dp.push_back(1);  
int p1 = 0, p2 = 0, p3 = 0;  

for(int i = 1; i < n; i++)
{
    int two = dp[p1] * 2;
    int thr = dp[p2] * 3;
    int fiv = dp[p3] * 5;

    int nextUgly = min(two, min(thr, fiv));  
    dp.push_back(nextUgly);  

    if (nextUgly == two) p1++;
    if (nextUgly == thr) p2++;
    if (nextUgly == fiv) p3++;
}

        return dp[n-1];
    }
};