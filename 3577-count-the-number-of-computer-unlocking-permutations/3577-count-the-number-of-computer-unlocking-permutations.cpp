class Solution {
public:
int mod = 1e9 + 7;
    int fact(int n){
        if(n == 1) return 1;
        return (1ll*n*fact(n-1))%mod;
    }
    int countPermutations(vector<int>& complexity) {
        map<int,int> M;
        int n = complexity.size();
        for(auto x : complexity){
            M[x]++;
        }
       // cout<<M.begin()->first<<endl;
        if(M.begin()->first == complexity[0] && M.begin()->second == 1) return fact(n-1);
          else return 0;

    }
};