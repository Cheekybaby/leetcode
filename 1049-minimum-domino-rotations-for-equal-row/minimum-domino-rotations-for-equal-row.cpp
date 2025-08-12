class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<vector<int>> v (7, vector<int> ());

        for(int i=0; i<n; i++){
            if (tops[i] == bottoms[i]) v[tops[i]].push_back(i);
            else {
                v[tops[i]].push_back(i);
                v[bottoms[i]].push_back(i);
            }
        }      
        int min_swaps = INT_MAX;
        for(int i=1; i<7; i++){
            if (v[i].size() == n){ // Potential Candidate
                // Calculate the number of swaps needed
                int up = 0, down = 0;
                for(int j=0; j<n; j++){
                    if (tops[j] != i) up++;
                    if (bottoms[j] != i) down++;
                }

                min_swaps = min({min_swaps, up, down});
            }
        }

        return (min_swaps == INT_MAX) ? -1 : min_swaps;
    }
};