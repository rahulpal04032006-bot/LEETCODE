class ProductOfNumbers {
    private:
    vector<int>temp;
public:
    ProductOfNumbers() {
        temp.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            temp.clear();
            temp.push_back(1);
        }else{
            temp.push_back(temp.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = temp.size();
        if(k >= n){
            return 0;
        }
        return temp[n-1] / temp[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */