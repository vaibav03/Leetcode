class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string start = "11";
        for(int i=1;i<n-1;i++){
            string temp = "";
            int prev = start[0],pres = -1,cnt = 1;
            for(int j=1;j<start.size();j++){
                 pres  = start[j];
                 if(pres == prev) cnt++;
                 else{
                    temp+=(cnt+'0');
                    temp+=(prev);
                    cnt = 1;
                 }
                 prev = pres;
            }
                 temp+=(cnt+'0');
                 temp+=(prev);
            cout<<temp<<" ";
           start = temp;
           temp="";
        }
        return start;
    }
};