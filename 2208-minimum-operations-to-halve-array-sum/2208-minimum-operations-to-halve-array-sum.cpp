class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(),nums.end(),0LL);
        int op{};
        double target = sum;
        priority_queue<double> pq(nums.begin(),nums.end()); 
        while(target > sum/2.0){
            double tope = pq.top();
            pq.pop();
            target -= tope/2.0;
            pq.push(tope/2.0);
            op++;
        }
        return op;
    }
};