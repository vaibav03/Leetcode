class Solution {
public:
   void c2(vector<int> candidates,int ind,int target, vector<int> &res,vector<vector<int>> &ans){
        if(target == 0 ) {
            ans.push_back(res);
            return ;
            }
            
        if(ind>=candidates.size()) return;  

        if(candidates[ind]<=target){
            res.push_back(candidates[ind]);   
            cout<<ind<<" ";
            for(int i=0;i<res.size();i++){
                cout<<res[i]<<" ";
            }       
            cout<<endl;

            c2(candidates,ind+1,target - candidates[ind],res,ans);
            res.pop_back();
        }else{
            return;
        }

            while(ind<candidates.size()-1 && candidates[ind]==candidates[ind+1]) {
            ind++;
            }
             c2(candidates,ind+1,target,res,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> res;
        vector<vector<int>> ans;
        c2(candidates,0,target,res,ans);

        return ans;
    }
};