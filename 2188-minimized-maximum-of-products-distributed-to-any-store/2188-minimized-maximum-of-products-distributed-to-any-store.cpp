class Solution {
public:
bool f(int n, std::vector<int> &quantities, int x) {
    for (int quantity : quantities) {
        n -= ceil((float)quantity / x);
        if (n < 0) {
            return false;
        }
    }
    return true;
}

    int minimizedMaximum(int n, vector<int>& quantities) {
            int l = 1,r = *max_element( quantities.begin(), quantities.end());  
            int ans = r;
            while(l<=r){
            int mid = (l+r)/2;
            if(f(n,quantities,mid))
            {
             ans = mid;   
             r = mid-1;
            }
            else{
                l = mid + 1;
            }
            }
        return ans;
    }
};