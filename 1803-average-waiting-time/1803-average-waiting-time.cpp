class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curr_w{},curr_f{},prev_w{},prev_f{};
        double ans{};
        for(int i=0;i<customers.size();i++){
            curr_w = max(0,prev_f-customers[i][0]) + customers[i][1];
            curr_f = max(prev_f,customers[i][0]) + customers[i][1];

            ans+= curr_w;
            prev_w = curr_w;
            prev_f = curr_f;
        }
        return (ans*1.0/customers.size());
    }
};