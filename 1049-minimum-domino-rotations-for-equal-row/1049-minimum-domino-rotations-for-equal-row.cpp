class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int> M;
        int ans=INT_MAX;
        for(int i=0;i<tops.size();i++){
            M[tops[i]]++;
            M[bottoms[i]]++;
        }

        for (auto i : M){

            int moves_top{},moves_bot{};
            for(int ind = 0;ind<tops.size();ind++){
                if(i.first== tops[ind] && i.first!=bottoms[ind]){
                        moves_bot++;
                }

                if(i.first == bottoms[ind] && i.first!=tops[ind]){
                    moves_top++;
                }
                if(i.first!=tops[ind] && i.first!=bottoms[ind]){
                    moves_bot = INT_MAX;
                    moves_top = INT_MAX;
                    break;
                }
            }
            ans = min(ans,min(moves_bot,moves_top));
        }

        return (ans==INT_MAX) ?  -1 :  ans ;
    }
};