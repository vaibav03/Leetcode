class Robot {
public:
    int w,h;
    int x{},y{},dir{};
    int perim;
    vector<vector<int>> dirs  = {{1,0},{0,1},{-1,0},{0,-1}};
    Robot(int width, int height) {
        w = width;
        h = height;
        perim = 2*w +2*h - 4;
    }
    
    void step(int num) {
        num%=perim;
            if (num == 0) {
        if (x == 0 && y == 0) dir = 3; 
        return;
    }

        int nx = x + num*dirs[dir][0], ny = y + num*dirs[dir][1];
        int stepsLeft = 0;
        if(nx<0 || nx>=w ){ 
         stepsLeft = (nx<0) ? abs(nx) : abs(nx - (w-1));

        x = (nx<0) ? 0 : w - 1; 
        dir = (dir+1)%4; 
        }
        else{ x = nx; }
        if(ny <0 || ny>=h){ 
            stepsLeft = (ny<0) ? abs(ny) : abs(ny - (h-1));
            y = (ny<0) ? 0 : h - 1; 
            dir = (dir+1)%4; 
        }
        else{ y = ny; }

        if(stepsLeft > 0)
        step(stepsLeft);
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir == 0) return "East";
        else if( dir == 1) return "North";
        else if(dir == 2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */