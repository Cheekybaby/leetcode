class Solution {
public:
    int numTilePossibilities(string tiles) {
        int count[26] = {0};

        for(char c:tiles){
            count[c - 'A']++;
        }

        return solve(count);
    }

private:
    int solve(int count[26]) {
        int total = 0;
        for (int i=0; i<26; i++){
            if (count[i] == 0) continue;

            count[i]--;
            total += (1 + solve(count));
            count[i]++;
        }

        return total;
    }
};