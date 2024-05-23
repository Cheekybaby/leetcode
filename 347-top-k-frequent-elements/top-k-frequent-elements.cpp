class Solution {
public:
    static bool cmp(pair<int,int> &p, pair<int,int> &q){
        return p.first>q.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for (int i=0; i<nums.size(); i+=1){
            mpp[nums[i]]+=1;
        }
        vector<pair<int,int>> v;
        for (auto it:mpp){
            v.push_back(make_pair(it.second, it.first));
        }
        vector<int> ans;
        sort(v.begin(), v.end(), cmp);

        for (auto it:v){
            if (k == 0) break;
            ans.push_back(it.second);
            k-=1;
        }
        return ans;
    }
};