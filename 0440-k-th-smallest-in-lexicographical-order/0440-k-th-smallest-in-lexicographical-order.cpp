class Solution {
public:
    int count(int n,long long curr){
        int res = 0;
        long long  nei = curr+1;
        while(curr<=n){
            res+= (min(nei,1ll*(n+1)) -curr);
            curr*=10;
            nei*=10;
        }
        return res;
    }
    int findKthNumber(int n, int k) {
     int curr = 1,i=1;
     while(i<k){
        int steps  = count(n,curr*1ll);
        if(i+steps<= k){
            curr++;
            i+=steps;
        }else{
            curr *= 10;
            i++;
        }
     }

     return curr;
    }
};