class Solution {
public:
    void rec(int pres,int n,vector<int> & ans){
        if(pres>n) return;

        if(pres!=0) ans.push_back(pres);

        for(int i=0;i<10;i++){
            if(pres==0 && i==0)  continue;

            rec(pres*10+i,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        rec(0,n,ans);
        return ans;
    }
};