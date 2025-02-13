class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto &it:nums){
            pq.push(it);
        }

        int ans = 0;

        while(pq.top() < k){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            
            long long z = min(x, y) * 2 + max(x, y);

            pq.push(z);

            ans += 1;
        }

        return ans;
    }
};