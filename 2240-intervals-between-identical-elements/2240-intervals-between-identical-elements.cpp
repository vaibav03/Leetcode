class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        map<int,pair<long long,long long>> M;
        int n= arr.size();
        vector<long long> ans(n,0);
        for(int i=0;i<n;i++){
            if(M.find(arr[i]) == M.end()){
                M[arr[i]] = {i,1};
            }else{
                auto it = M[arr[i]];
                long long cnt = it.second ,pre= it.first;
                ans[i] +=  cnt*i - pre;
                M[arr[i]].second++;
                M[arr[i]].first+=i;
            }
            cout<<i<<" "<<ans[i]<<endl;
        }
        M.clear();
        for(int i = n-1;i>=0;i--){
            if(M.find(arr[i]) == M.end()){
                M[arr[i]] = {i,1};
            }else{
                auto it = M[arr[i]];
                long long cnt = it.second ,suf= it.first;
                ans[i] +=  suf - cnt*i;
                M[arr[i]].second++;
                M[arr[i]].first+=i;
            }
        }
        return ans;
    }
};