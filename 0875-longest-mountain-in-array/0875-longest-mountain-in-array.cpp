class Solution {
public:
    int longestMountain(vector<int>& arr) {
    int ans{};
       for(int i=1;i<arr.size()-1;i++){
        if(arr[i]>arr[i-1] && arr[i+1]<arr[i]){
            int l=i-1,r=i;
            while(l>=0 && arr[l]<arr[l+1]) l--;
            while(r<arr.size()-1 && arr[r]>arr[r+1] ) r++;
            cout<<l<<' '<<i<<" "<<r<<endl;
            ans = max(ans,r-l);
        }
       }
       return ans;
    }
};