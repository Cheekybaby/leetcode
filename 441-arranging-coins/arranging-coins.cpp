using ll = long;
class Solution {
public:
    int arrangeCoins(int n) {
        ll left = 1, right = n;
        while (left<right){
            ll mid = (left+right+1)/2;
            ll f = mid*(mid+1)/2;
            if (f>n){
                right = mid-1;
            } else {
                left = mid;
            }
        }

        return left;
    }
};