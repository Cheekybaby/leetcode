class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1){
            return 0;
        }
        vector<bool> prime(n+1, true);
        prime[0] = false;
        prime[1] = true;
        int count = 0;
        for (int i=2; i<n; i++){
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