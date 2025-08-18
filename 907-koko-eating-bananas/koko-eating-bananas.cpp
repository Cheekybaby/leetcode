class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1;
        int j = *max_element(piles.begin(), piles.end());

        int min_speed = j;
        while(i <= j){
            int mid = midpoint(i, j);
            long long hours = 0;
            for(auto &b:piles){
                hours += (ceil((double)b/mid));
            }

            if (hours <= h){
                min_speed = min(min_speed, mid);
                j = mid - 1;
            }
            else i = mid + 1;
        }

        return min_speed;
    }
};