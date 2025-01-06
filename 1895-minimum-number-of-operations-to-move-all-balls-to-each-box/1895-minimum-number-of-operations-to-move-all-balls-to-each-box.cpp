class Solution {
public:
    vector<int> minOperations(string boxes) {
        int dist{},numb{},numa{};
        for(int i=1;i<boxes.size();i++){
            if(boxes[i]-'0'){
                dist+=i;
                numb++;
            }
        }
        vector<int> ans(boxes.size(),0);
        ans[0] = dist;
        if(boxes[0]-'0'){
            for(int i=1;i<boxes.size();i++){
            ans[i] = ans[i-1] - numb + numa + 1;
            if(boxes[i]-'0'){
                numb--;
                numa++;
            }
        }
        }
        else{
            for(int i=1;i<boxes.size();i++){
            ans[i] = ans[i-1] - numb + numa ;
            if(boxes[i]-'0'){
                numb--;
                numa++;
            }
        }
    }
    return ans;
    }
};