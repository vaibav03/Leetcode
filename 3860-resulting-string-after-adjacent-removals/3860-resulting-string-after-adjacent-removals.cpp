class Solution {
public:
    string resultingString(string s) {
        string sb="";
        for(char x : s){
            if(sb.empty()){
                sb.push_back(x);
            }else if(abs(sb.back() - x) == 1 || abs(sb.back()-x) == 25 ){
                sb.pop_back();
            }else{
                sb.push_back(x);
            }
        }
        return sb;
    }
};