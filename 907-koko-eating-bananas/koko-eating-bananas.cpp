class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r = 0;
        for(int i=0; i<piles.size(); i++){
            r = max(r, piles[i]);
        }

        int min_speed = r;

        while (l <= r){
            int mid = l + (r - l)/2;
            long long hours = 0;
            for(int i=0; i<piles.size(); i++){
                hours += ceil((double)piles[i]/mid);
            }

            if (hours <= h){
                min_speed = min(min_speed, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return min_speed;
    }
};