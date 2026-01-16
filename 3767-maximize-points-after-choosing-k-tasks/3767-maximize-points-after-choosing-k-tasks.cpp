class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        long long sum = accumulate(t1.begin(),t1.end(),0LL);
        priority_queue<int> pq;
        for(int i=0;i<t1.size();i++){
            pq.push(t2[i] - t1[i]);
        }
        int chosen = 0, n = t1.size();
        while(chosen < n - k){
            if(pq.top() > 0){ sum += pq.top(); pq.pop(); chosen++; }
            else break;
        }

        return sum;
    }
};