class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;

        unordered_set<int> st1, st2;
        for (int i=0; i<nums1.size(); i+=1){
            st1.insert(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i+=1){
            st2.insert(nums2[i]);
        }
        unordered_set<int> first;
        for (int i=0; i<nums1.size(); i+=1){
            if (st2.count(nums1[i]) == 0){
                first.insert(nums1[i]);
            }
        }
        unordered_set<int> second;
        for (int i=0; i<nums2.size(); i+=1){
            if (st1.count(nums2[i]) == 0){
                second.insert(nums2[i]);
            }
        }
        vector<int> f(first.begin(), first.end());
        ans.push_back(f);
        vector<int> s(second.begin(), second.end());
        ans.push_back(s);
        return ans;
    }
};