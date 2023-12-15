class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1 || n == 2){
            return 0;
        }
        vector<bool> prime(n+1, true);
        prime[0] = false;
        prime[1] = false;
        int count = 1;
        for (int i=3; i<n; i+=2){
            if (prime[i]){
                count+=1;
                for (int j=2*i; j<n; j+=i){
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};