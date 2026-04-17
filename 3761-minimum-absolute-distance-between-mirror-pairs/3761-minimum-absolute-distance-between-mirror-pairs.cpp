class Solution {
public:
    int reverse(int n){
        int ans{},powe  = 0, dupe = n;
        while(n/(long long )pow(10,powe) !=0){  powe++;}

        powe --;
        //cout<< powe<<endl;
        while(n){
            ans += ((n%10) * pow(10,powe));
            powe--;
            n/=10;
        }
    return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {

        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int rev = reverse(nums[i]);
            if(!mpp.count(rev) ) continue;

            int ind = lower_bound(mpp[rev].begin(),mpp[rev].end(),i) - mpp[rev].begin(),k = mpp[rev].size();
        if(ind != k && mpp[rev][ind] > i) ans = min(ans, mpp[rev][ind]- i);
        else if(ind < k-1 && mpp[rev][ind] == i) ans = min(ans, mpp[rev][ind+1]- i);
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};