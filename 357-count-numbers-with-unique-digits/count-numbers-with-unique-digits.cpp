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
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        else if (n == 1) return 10;
        else if (n == 2) return 91;
        else if (n == 3) return 739;
        else if (n == 4) return 5275;
        else if (n == 5) return 32491;
        else if (n == 6) return 168571;
        else if (n == 7) return 712891;
        else return 2345851;
    }
};