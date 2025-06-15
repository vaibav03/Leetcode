// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l =1, r = n;

        while(l<r){
            int mid = (1ll*(1ll*l+1ll*r))/2;
            cout<<l<<" "<<mid<<" "<<r<<endl;
            if(!isBadVersion(mid)){
                l = mid+1;
            }else{
                r = mid;
           }
        }
        return l;
    }
};