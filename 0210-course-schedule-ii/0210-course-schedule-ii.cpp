class Solution {
public:
    vector<int> ans;
    bool isCycle(vector<vector<int>> &adj,vector<int> &vis , int v){
        vis[v] = 2;
        for(auto neigh : adj[v]){
            if(vis[neigh] == 2) return true;
            else if(!vis[neigh] && isCycle(adj,vis,neigh) == true) return true; 
        }
        vis[v] = 1;
        return false;
    }
    void toposort(vector<vector<int>> &adj,vector<int> &vis , int v){
        vis[v] = 1;
        for(auto neigh : adj[v]){
            if(!vis[neigh]) toposort(adj,vis,neigh);
        }
        ans.push_back(v);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0);
        for(auto prereq : prerequisites){
            adj[prereq[0]].push_back(prereq[1]);
        }

        for(int i=0;i<numCourses;i++){
            if(!vis[i] && isCycle(adj,vis,i)) return {}; 
        }
        for(int i=0;i<numCourses;i++) vis[i] = 0;

        for(int i=0;i<numCourses;i++){
            if(!vis[i]) toposort(adj,vis,i);
        }
        return ans;  
    }
};