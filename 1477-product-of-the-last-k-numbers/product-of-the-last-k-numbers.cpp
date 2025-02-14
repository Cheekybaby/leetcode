class ProductOfNumbers {
public:
    vector<int> ip{1};
    ProductOfNumbers() {}
    
    void add(int num) {
        if (num != 0) {
            ip.push_back(num*ip.back());
        }
        else {
            ip.clear();
            ip.push_back(1);
        }
    }
    
    int getProduct(int k) {
        return (k < ip.size()) ? (ip.back() / ip[ip.size() - k - 1]) : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */