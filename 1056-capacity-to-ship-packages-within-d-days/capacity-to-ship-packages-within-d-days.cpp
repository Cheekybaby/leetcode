class Solution {
private:
    bool canShip(vector<int> &weights, int cap, int days){
        int ships = 1, curr_cap = cap;
        for(auto w:weights){
            if (w > curr_cap){
                ships++;
                if (ships > days) return false;
                curr_cap = cap;
            }
            curr_cap -= w;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int min_capacity = r;
        while (l <= r){
            int mid = l + (r-l)/2;
            if(canShip(weights, mid, days)){
                min_capacity = min(min_capacity, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return min_capacity;
    }
};