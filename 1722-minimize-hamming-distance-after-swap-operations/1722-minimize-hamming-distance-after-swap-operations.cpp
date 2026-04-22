class Solution {
public:

    class DSU{
        public:
        vector<int> parent;
        vector<int> rank;
        DSU(int n){
            parent.resize(n, -1);
            rank.resize(n,0);
            for(int i=0;i<parent.size();i++){
                parent[i] = i;
            }
        }
        int findParent(int u){
            if(parent[u] == u) return u;
            
            return parent[u] = findParent(parent[u]);
        }
        void Union(int u ,int v){
            int pu = findParent(u),pv = findParent(v);
            if(pu == pv ) return ;

            if(rank[pu] > rank[pv]){
                parent[pv] = pu;
                rank[pu]++;
            }else {
                parent[pu] = pv;
                rank[pv]++;
            }
        } 
    };
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        DSU dsu(n);
        for(auto x : allowedSwaps){
            dsu.Union(x[0],x[1]);
        }
        unordered_map<int, unordered_map<int,int>> mpp;
        for(int i=0;i<source.size();i++){
            int par = dsu.findParent(i);

            mpp[par][source[i]]++;
        }

        for(auto x : mpp){
            for(auto y : mpp[x.first]){
                cout<<x.first<<" "<<y.first<<" "<<y.second<<endl;
            }
        }
        int ans{};
        cout<<" befifebj"<<endl;
        for(int i=0;i<source.size();i++){
            int par = dsu.findParent(i);
            //cout<<par<<" "<<target[i]<<" "<<mpp[par][target<<endl;
            if(mpp[par].count(target[i]) > 0 && mpp[par][target[i]]>0 ){
                mpp[par][target[i]]--;
            }else{
                ans++;
            }
        }
        return ans;
    }
};