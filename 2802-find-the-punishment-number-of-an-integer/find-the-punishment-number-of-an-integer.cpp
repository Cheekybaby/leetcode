class Solution {
public:
    vector<int> lookupTable = {1, 81, 100, 1296, 2025, 3025, 6724, 8281, 9801, 10000, 55225, 88209, 136161, 136900, 143641, 171396, 431649, 455625, 494209, 571536, 627264, 826281, 842724, 893025, 929296, 980100, 982081, 998001, 1000000};
    int punishmentNumber(int n) {
        int ans = 0;
        int i=0;
        int val = n*n;
        while((i<lookupTable.size()) && (lookupTable[i] <= val)){
            ans += lookupTable[i];
            i++;
        }

        return ans;
    }
};