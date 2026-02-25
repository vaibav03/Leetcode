class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int &a,int &b){
            int cnt1{},cnt2{};
            for(int i=0;i<31;i++){
                if(a&(1<<i)){ cnt1++; }
                if(b&(1<<i)){ cnt2++; }
            }
            if (cnt1 == cnt2) return (a<b);
            else return (cnt1 < cnt2);
        });
        return arr;
    }
};