class Solution {
public:
    int numberofSubarrays(vector<int> &v, int x){
        if (x<=0) return 0;
        int i=0, j=0;
        int ans = 0, pro = 1;
        while (j<v.size()){
            pro*=v[j];

            while (pro>x){
                pro/=v[i];
                i+=1;
            }

            ans+=(j-i+1);
            j+=1;
        }

        return ans;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        return numberofSubarrays(nums, k-1);
    }
};