class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       // auto [root_x,root_y] = points[0];

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        unordered_set<int> s;
        int ans{};
        pq.push({0,0});
        
        while(!pq.empty()){
            auto [dist,node] = pq.top();
            pq.pop();
            if(s.count(node)) continue;
            
            s.insert(node);
            ans+=dist;

            cout<<node<<endl;

            if(s.size() == points.size()) break;

            for(int i=0;i<points.size();i++){
                if(!s.count(i)){
                    int edg = abs(points[node][0] - points[i][0]) + abs(points[i][1] - points[node][1]);
                    pq.push({edg,i}); 
                    
                }
            }
        }
        return ans;
    }
};