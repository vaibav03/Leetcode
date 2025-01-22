class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height (m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    pq.push({0,i,j});
                }
            }
        }
        if(pq.empty()){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(!i)
                    height[i][j] = min(height[i-1][j],height[i][j]);
                    if(!j)
                    height[i][j] = min(height[i][j-1],height[i][j]);

                    height[i][j]+=1; 
                }
            }
            return height;
        }
        else{
           vector <int> row = {1,-1,0,0},col = {0,0,1,-1};
            while(!pq.empty()){
                auto vec = pq.top();
                int h = vec[0],i=vec[1],j = vec[2];
                pq.pop();
                for(int ind=0;ind<4;ind++){
                    int new_row = i+row[ind],new_col = j+col[ind];
                    if(new_row>=0 && new_row<m && new_col>=0 && new_col<n && height[new_row][new_col]==INT_MAX){
                    height[new_row][new_col] = h+1;
                    pq.push({h+1,new_row,new_col});
                    }
                }
            }
            return height;
        }

    }
};