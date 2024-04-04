class Solution {
public:
    int sumofDigits(int x){
        int sum = 0;
        while (x>0){
            sum += (x%10);
            x/=10;
        }

        return sum;
    }
    int sumOfTheDigitsOfHarshadNumber(int x) {
        if (x % sumofDigits(x) == 0){
            return sumofDigits(x);
        }
        return -1;
    }
};