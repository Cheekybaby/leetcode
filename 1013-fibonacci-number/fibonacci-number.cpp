class Solution {
public:
    int arr[31];
    bool check[31];


    int fib(int n) {
        if (check[n]) return arr[n];
        if (n == 0) return 0;
        if (n <= 2) return 1;

        return arr[n] = fib(n-1) + fib(n-2);    
    }
};