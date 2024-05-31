class Solution {
public:
    int numberofSubarrays(vector<int> &v, int x){
        int i=0, j=0;
        int ans = 0, sum=0;
        if (x < 0) return 0;
        while(j<v.size()){
            sum+=v[j];

            while (sum>x){
                sum-=v[i];
                i+=1;
            }

            ans+=(j-i+1);
            j+=1;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numberofSubarrays(nums, goal) - numberofSubarrays(nums, goal-1);   
    }
};