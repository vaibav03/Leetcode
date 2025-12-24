class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end(),[](int &a, int &b){
            return a > b;
        });

        int i{},acc{};
        while(acc < total){
            acc+=capacity[i];
            i++;
        }
        return i;
    }
};