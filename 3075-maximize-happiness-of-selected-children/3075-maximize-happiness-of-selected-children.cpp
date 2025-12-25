class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
       sort(happiness.begin(),happiness.end());
       int sub = k-1;
       int n = happiness.size();
       for(int i = n - k ;i<n;i++){
        
        happiness[i] = max(happiness[i]-sub,0);
        sub--;
       } 
       for(auto x : happiness) cout<<x<<' ';
       return accumulate(happiness.end() - k,happiness.end(),0LL);
    }
};