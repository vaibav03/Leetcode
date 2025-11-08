class Solution {
public:
    void init(vector<int> & nums,unordered_map<int,int> &par,unordered_map<int,int> &rank){
        for(auto x : nums){
            par[x] = x;
            rank[x] = 1;
        }
    }   
    int findparent(unordered_map<int,int> &par ,int u){
        if(par[u] == u ) return u;

        return par[u] = findparent(par,par[u]);
    }

    void join(unordered_map<int,int> &par ,unordered_map<int,int> &rank,  int u , int v){
        u = findparent(par,u);
        v = findparent(par,v);
    if(u == v) return ;

    if(rank[u] > rank[v]){
        par[v] = par[u];
        rank[u]+=rank[v];
    }else{
        par[u] = par[v];
        rank[v]+=rank[u];
    }   
}


    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
       unordered_map<int,int> par,rank;
       int ans = 1;
       init(nums,par,rank);
       for(int x : nums){
            if(par.count(x - 1)) join(par, rank, x, x - 1);
            if(par.count(x + 1)) join(par, rank, x, x + 1);
        }
        cout<<"parent"<<endl;
    for(auto x : par){
        cout<<x.first<<" "<<x.second<<endl;
    }
            cout<<"rank"<<endl;
            for(auto x : rank){
        cout<<x.first<<" "<<x.second<<endl;
    }

    for(auto x : rank){
        ans = max(ans,x.second);
    }
       return ans;
    }
};