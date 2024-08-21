class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> v(n+1,true);
        v[0]=0;
        v[1]=0;
        for(int i=2;i<=sqrt(n);i++)
        {
         if(v[i]){
           for(int j=i*i;j<=n;j+=i){
            v[j]=false;
           } 
         }   
        }

        vector<vector<int>> ans;

        for(int i=n-2;i>=ceil((float)n/2);i--){
           if(v[i] && v[n-i])
            ans.push_back({n-i,i}); 
        }
    return ans;
    }
};