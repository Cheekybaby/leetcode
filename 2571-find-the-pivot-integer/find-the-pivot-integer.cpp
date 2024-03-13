class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int temp = 0, i=1;
        while (temp<sum){
            temp+=i;
            if (temp == (sum-temp+i)){
                return i;
            }
            i+=1;
        }
        return -1;
    }
};