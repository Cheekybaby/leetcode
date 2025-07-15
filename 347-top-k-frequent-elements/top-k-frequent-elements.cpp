class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &it:m){
            pq.push({it.second, it.first});
        }

        vector<int> k_freq;
        while(k--){
            int val = pq.top().second;
            k_freq.push_back(val);
            pq.pop();
        }

        return k_freq;
    }
};