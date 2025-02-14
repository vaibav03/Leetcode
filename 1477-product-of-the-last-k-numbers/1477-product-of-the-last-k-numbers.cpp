class ProductOfNumbers {
    private:
    vector<int> pre;
    int size = 0;
public:
    ProductOfNumbers() {
     pre = {1};
     size = 1;
    }
    
    void add(int num) {
        if(num==0){
            pre = {1};
            size = 1;
        }
        else{
        pre.push_back(pre[size-1]*num);
        size++;
        }  
    }
    
    int getProduct(int k) {
        if(k>=size) return 0;
        else return pre[size-1]/pre[size-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */