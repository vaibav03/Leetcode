class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int bw = meetings[0][0] - 1,last = meetings[0][1];
        for(int i=1;i<meetings.size();i++){
            if(last < meetings[i][0]){
                bw+= (meetings[i][0] - last - 1);
                cout<<last<<" "<<meetings[i][0]<<endl;
            }

        
        last = max(meetings[i][1],last);
        }
        if(last < days)
        bw+= (days - last);
        return bw;
    }
};