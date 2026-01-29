class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26,vector<long long>(26,1e9));
        for(int i=0;i<original.size();i++){
            int org = original[i]-'a', ch = changed[i]-'a';
            adj[org][ch] = min(adj[org][ch] , 1ll*cost[i]);
        }
        for(int i=0;i<26;i++){
            adj[i][i] = 0;
        }

            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    for(int k=0;k<26;k++){
                        adj[j][k] = min(adj[j][k] , adj[j][i] + adj[i][k]);
                    }
                }
            }

        long long ans{};
        for(int i=0;i<source.size();i++){
            int org = source[i] - 'a', ch = target[i] - 'a';
            if(org == ch) continue;


            if(adj[org][ch] != 1e9){
                ans += adj[org][ch];
            }else {
                cout<<org<<" "<<ch<<endl;
                return -1;
            }

        } 
        return ans;
    }
};