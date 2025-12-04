class Solution {
public:
    int countCollisions(string directions) {
        int pre{},ans{},i{};
        while(i<directions.size() && directions[i]=='L') i++;
        
        for(;i<directions.size();i++){
            if(directions[i] == 'R'){
                pre--;
            }else if(directions[i] == 'L'){
                if(pre <= 0){
                    ans+= (abs(pre) + 1);
                    pre = 0;
                }
            }else{
                if(pre < 0 ){ ans+=abs(pre); pre = 0;}
            }
        }
        return ans;
    }
};