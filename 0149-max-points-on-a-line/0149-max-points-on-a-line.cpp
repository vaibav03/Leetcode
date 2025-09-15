class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi{};
        for(int i=0;i<points.size();i++){
            unordered_map<double,int> M;
            cout<<i<<endl;
            for(int j=0;j<points.size();j++){
                if(i!=j){
                    double slope = INT_MAX;
                    if(points[i][0]-points[j][0]!=0)
                    slope = (double) ((points[i][1]-points[j][1])*1.0/(points[i][0]-points[j][0]));

                    M[slope]++;
                }
            }
            cout<<endl;
            for(auto x : M){
                if(x.second>maxi){
                    
                    maxi = x.second;
                }
            }
        }
        return maxi+1;
    }
};