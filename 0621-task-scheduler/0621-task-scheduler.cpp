class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    priority_queue<pair<int,int>> pq;
    map<int,int> M;
    for(int i=0;i<tasks.size();i++){
        M[tasks[i]-'A']++;
    }
    int ans{},cycle = n;
    for(auto x : M){
        pq.push({x.second,x.first});
    }

    while(!pq.empty()){
        cycle = n + 1;  
        vector<pair<int,int>> temp;

        while(cycle > 0 && !pq.empty()){
            auto x = pq.top();
            pq.pop();
            M[x.second]--;
            ans++; 
            if(M[x.second] == 0) M.erase(x.second);
            else temp.push_back({M[x.second], x.second});
            cycle--;
        }

        for(auto &y : temp){
            pq.push(y);
        }

        if(!pq.empty()) ans += cycle;
    }

    return ans;
}

};