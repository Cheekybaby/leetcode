/*
- Given an integer n, return all the numbers with unique digits
- The number should have all the digits different
- The range we need to find is given by 10^n where n is given to us.

- How do we figure out how many numbers are in given range
    - For n = 0, it is 1
    - For n = 1, it is 10
    - For n = 3, it is 91
    - For n = 4, it is 5275
    - For n = 5, it is 32491
    - For n = 6, it is 168571
    - For n = 7, it is 712891
    - For n = 8, it is 2345851

- 
*/

class Solution {
public:
    int solve(int n){
        if (n <= 1) return 1;
        return n * solve(n-1);
    }
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        int x = solve(9);
        for (int i=1; i<=min(9, n); i+=1){
            int y = solve(10 - i);
            ans+=(9*(x/y));
        }

        return ans;
    }
};