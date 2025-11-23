class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> hash;
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }
        int ans{},rem{};
        priority_queue<int> pq;
        for(auto x : hash){
            pq.push(x.second);
        }
        while(!pq.empty() && rem<arr.size()/2){
            cout<<pq.top()<<endl;
            rem+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};