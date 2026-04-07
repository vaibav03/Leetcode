class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int lim = pow(n, (float) 1/3);
        unordered_map<int,int>  hash;

        for(int i=1;i<=lim;i++){
            for(int j=1;j<=i;j++){
                int num = i*i*i + j*j*j;
                hash[num]++;
            }
        }
        vector<int> ans;
        for(auto num :  hash){
            if(num.first <= n && num.second  >=2) ans.push_back(num.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};