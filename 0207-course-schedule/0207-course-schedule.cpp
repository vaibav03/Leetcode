class Solution {
public:
    bool doesCycleExist(const vector<vector<int>>& adj,
                        vector<int> &vis,
                        int v,
                        vector<int> &parent) {
        parent[v] = 1;

        for (int x : adj[v]) {
            if (parent[x]) {            
                return true;            
            }
            if (!vis[x]) {              
                vis[x] = 1;
                if (doesCycleExist(adj, vis, x, parent)) {
                    return true;       
                }
            }
        }

        parent[v] = 0; 
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);  
        }

        vector<int> vis(numCourses, 0);
        vector<int> parent(numCourses, 0); 

        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i]) {
                vis[i] = 1;
                if (doesCycleExist(adj, vis, i, parent)) {
                    return false;       
                }
            }
        }
        return true; 
    }
};
