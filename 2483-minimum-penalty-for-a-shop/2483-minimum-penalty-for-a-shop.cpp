class Solution {
public:
    int bestClosingTime(string customers) {
        int mini = INT_MAX,ans=0,n = customers.size();
        vector<int> suf(n,0);
        int s{};
        for(int i=n-1;i>=0;i--){
            suf[i] = s;
            if(customers[i] == 'Y') s++;
        }
        int pre{};
        mini = s;
        for(int i=0;i<n;i++){
            if(customers[i] == 'N') pre++;

            if( suf[i]+pre < mini){
                mini = suf[i] + pre;
                ans = i+1;
            }
        }
        return ans;
    }
};