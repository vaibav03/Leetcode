class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i{},j{},ans{};
        map<int,int> M;
        while(j<fruits.size()){
            M[fruits[j]] = j;
            if(M.size()>2){
                int mine=INT_MAX;
                for(auto x : M){
                    mine = min(x.second,mine);
                }
                for(auto x : M){
                    if(x.second==mine) M.erase(x.first);
                }
                i = mine+1;
            } 
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
        }
};