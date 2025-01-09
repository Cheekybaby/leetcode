// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n;
        while(l <= r){
            long long mid = midpoint(l, r);
            if (isBadVersion(mid) == true){
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};