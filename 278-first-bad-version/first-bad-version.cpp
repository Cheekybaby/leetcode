// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 0, j = n;
        while (i <= j){
            int mid = midpoint(i, j);

            if (isBadVersion(mid) == false){
                i = mid + 1;
            } else{
                if (isBadVersion(mid-1) == false) return mid;
                else {
                    j = mid - 1;
                }
            }
        }

        return -1;
    }
};