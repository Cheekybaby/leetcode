class Solution {
public:
    long long maxelement(vector<int> &v){
        long long maxele = v[0];
        for (int i=1; i<v.size(); i+=1){
            maxele = max(maxele,(long long)v[i]);
        }

        return maxele;
    }

    long long timetoeat(vector<int> &v, long long k){
        long long time = 0;
        for (int i=0; i<v.size(); i+=1){
            time+=(ceil(static_cast<double>(v[i])/k));
        }

        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = maxelement(piles);
        int ans;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (timetoeat(piles, mid) <= h){
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }

        return ans;
    }
};