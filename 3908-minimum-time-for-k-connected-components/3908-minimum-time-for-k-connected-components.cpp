class Solution {
public:
    vector<int> rank,par;
    set<int> comp;

    int findPar(int u){
        if(par[u] == u) return u;
        return par[u] = findPar(par[u]);
    }

    void merge(int u,int v){
        u = findPar(u);
        v = findPar(v);
        if(u == v) return ;
        if(rank[u]<rank[v]){
            par[u] = par[v];
            comp.erase(u);
        }else if(rank[u]>rank[v]){
            par[v] = par[u];
            comp.erase(v);
        }else{
            rank[u]++;
            par[v] = par[u];
            comp.erase(v);
        }
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[2]>b[2];
        });

        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++) par[i] = i;

        int ans = 0, ind = 0;
        for(int i=0;i<n;i++) comp.insert(i);

        while(ind < edges.size() && comp.size() >= k){
            merge(edges[ind][1],edges[ind][0]);
            ans = edges[ind][2];
            ind++;
        }

        if(comp.size() >= k) return 0;
        return ans;
    }
};
