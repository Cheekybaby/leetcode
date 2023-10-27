class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum=INT_MIN, sum=0;
        for (int i=0; i<k; i++){
            sum+=cardPoints[i];
        }
        int j = 0;
        maxSum = max(sum, maxSum);
        while (j<k){
            sum-=cardPoints[k-1-j];
            sum+=cardPoints[cardPoints.size()-j-1];
            maxSum = max(sum, maxSum);
            j++;
        }

        return maxSum;
    }
};