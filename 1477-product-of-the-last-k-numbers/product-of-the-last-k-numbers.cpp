class ProductOfNumbers {
public:
    vector<int> ip;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ip.push_back(num);
    }
    
    int getProduct(int k) {
        int i = ip.size()-1;
        int product = 1;
        while(k--){
            product *= ip[i];
            i--;
        }

        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */