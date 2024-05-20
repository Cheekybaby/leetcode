class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        stack<int> st;

        for (int i=nums2.size()-1; i>=0; i-=1){
            int ele = nums2[i];

            while  (st.size()>0 && st.top()<=ele){
                st.pop();
            }

            if (st.size() == 0){
                mpp.insert({ele, -1});
            } else {
                mpp.insert({ele, st.top()});
            }

            st.push(ele);
        }


        for (auto it:nums1){
            ans.push_back(mpp[it]);
        }

        return ans;
    }
};