class Solution {
public:
    int fibonacci(int n){
        if (n==1 || n==2){
            return 1;
        } else {
            return fibonacci(n-1) + fibonacci(n-2);
        }
    }
    int fib(int n) {
        if (n == 0) return 0;
        return fibonacci(n);
    }
};