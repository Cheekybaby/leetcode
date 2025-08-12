/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    int findMatches(string &s, string &t){
        int match = 0;
        for(int i=0; i<6; i++){
            if (s[i] == t[i]) match++;
        }

        return match;
    }
public:
    void findSecretWord(vector<string>& words, Master& master) {
        set<string> candidates(words.begin(), words.end());
        for(int i=0, matches = 0; i < 30 && matches != 6; i++){
            int r = rand() % candidates.size();
            string g = *next(candidates.begin(), r);
            matches = master.guess(g);

            for(auto it = candidates.begin(); it != candidates.end(); ){
                string curr = *it;
                if (findMatches(g, curr) != matches) it = candidates.erase(it);
                else it++;
            }

            candidates.erase(g);
        }
    }
};