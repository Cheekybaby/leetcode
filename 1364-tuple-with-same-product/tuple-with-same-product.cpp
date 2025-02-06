class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int product = nums[i] * nums[j];
                m[product]++;
            }
        }
        int ans = 0;
        for(auto &it:m){
            int n = it.second;
            int comb = (n % 2) ? n * ((n-1)/2) : (n/2)*(n-1);

            ans += (comb * 8);
        }
        return ans;
    }
};