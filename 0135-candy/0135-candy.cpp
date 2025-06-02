class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> decRight(ratings.size());

        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                decRight[i] = decRight[i+1]+1;
            }
        }
        int ans{},prev{};

        for(int i=0;i<ratings.size();i++){

            if(i==0){
                ans+=(decRight[i]+1);
                prev = decRight[i]+1;
            }

            else if(ratings[i]>ratings[i-1]){
                ans+=max(prev+1,decRight[i]+1);
                prev++;
            }else{
                ans+=(decRight[i]+1);
                prev = decRight[i]+1;
            }
        }
        return ans;
    }
};