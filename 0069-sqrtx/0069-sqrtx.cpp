class Solution {
public:
    int mySqrt(int x) {
        long long l = 1, r = x;
        while(l<=r){
            long long mid = (l+r)/2ll;
            if(mid*1ll*mid == x) return mid;
            else if(mid*1ll*mid < x) l = mid+1;
            else r = mid - 1;

            //cout<<l<<" "<<mid<<" "<<r<<endl;
        }
        return r;
    }
};