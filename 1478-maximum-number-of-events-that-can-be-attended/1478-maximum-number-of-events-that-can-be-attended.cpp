class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[1]<b[1]) return true;
        else if(a[1]==b[1]) return(a[0]<b[0]);

        return false;
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int maxDay{},cnt{},i{};
        for(auto x : events){
            maxDay = max(maxDay,x[1]);
        }

        for(int day=0;day<=maxDay;day++){
            while(i<events.size() && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }

            if(!pq.empty()){
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};