class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end());
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        int ind_que{},ans{};
        for(int ind=0;ind<nums.size();ind++){
            if(nums[ind]==0) continue;

            while(!minHeap.empty() && minHeap.top()<ind){
                minHeap.pop();
            }

            while(ind_que<queries.size() && queries[ind_que][0]<=ind){
                maxHeap.push(queries[ind_que][1]);
                ind_que++;
            }

            while(minHeap.size()<nums[ind] && !maxHeap.empty() && maxHeap.top()>=ind){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                ans++;
            }

            if( !(minHeap.size()>=nums[ind]) ) return -1;
        }
        return queries.size() - ans;
    }
};