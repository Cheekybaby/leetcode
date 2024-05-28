class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i = cardPoints.size()-1;
        int j=0, l=cardPoints.size()-k;
        int sum = 0;
        while (k--){
            sum+=cardPoints[i];
            i-=1;
        }
        int ans = sum;
        while (l<cardPoints.size()){
            sum = sum + cardPoints[j] - cardPoints[l];
            ans = max(ans, sum);
            l+=1;
            j+=1;
        }

        return ans;
    }
};