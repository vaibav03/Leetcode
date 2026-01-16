class Solution {
public:
    double checkAns(vector<vector<int>>& squares , double y){
        double area = 0.0;
        for(int i=0;i<squares.size();i++){
            double xi = squares[i][0], yi = squares[i][1],l = squares[i][2];
            double curr = min( max( (double) y-yi , 0.00000) , (double) l);
            area +=  curr * l;
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double hi = 1e9, lo = 0;
        double area = checkAns(squares,INT_MAX),ans = 1e9;
       // cout<<area/2.00000<<endl;
        while(hi - lo >= 1e-6){
            cout<<(double)lo<<" "<<(double)hi<<endl;
            double mid = (lo+hi)/2.0;
            double curr = checkAns(squares, mid);
            
            if(curr < area/2.0) {
                lo = mid;
            }else{
                hi = mid;
            }
        }

        return hi;
        
    }
};