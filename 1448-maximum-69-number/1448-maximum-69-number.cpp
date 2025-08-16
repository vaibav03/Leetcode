class Solution {
public:
    int maximum69Number (int num) {
        int ans{},powe{},dupe = num,pos=-1;
        while(dupe){
            if(dupe%10==6) pos = powe;
            dupe/=10;
            powe++;
        }
     return (pos==-1) ? num : num + 3*pow(10,pos);  
    }
};