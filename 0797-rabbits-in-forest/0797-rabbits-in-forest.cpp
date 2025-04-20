class Solution {
public:
    int numRabbits(vector<int>& answers){
        map<int,int> M;
        for(int i=0;i<answers.size();i++){
            M[answers[i]]++;
        }

        int ans{};
        for(auto i : M){
          ans+=( (i.first+1)* (i.second/(i.first+1)));
          if(i.second%(i.first+1))
          ans+=(i.first+1);
        }
        return ans;
    }
};