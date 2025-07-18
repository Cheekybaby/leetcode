class Solution {
public:
    int hammingWeight(int n) {
        int weight = 0;
        while (n > 0){
            int bit = n & 1;
            if (bit == 1) weight += 1;
            n >>= 1;
        }
        return weight;
    }
};