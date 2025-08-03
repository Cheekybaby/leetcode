class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size(), m = waterStartTime.size();
        for(int i=0; i<n; i++){
            int first_end = landStartTime[i] + landDuration[i]; // When the current slide stops
            int temp = INT_MAX;
            for(int j=0; j<m; j++){
                int start = waterStartTime[j];
                int end = waterStartTime[j] + waterDuration[j];
                if (start > first_end){
                    // The total time will end
                    temp = min(temp, end);
                } else if (start == first_end){
                    temp = min(temp, first_end + waterDuration[j]);
                } else {
                    temp = min(temp, first_end + waterDuration[j]);
                }
            }
            ans = min(temp, ans);
        }

        for(int i=0; i<m; i++){
            int first_end = waterStartTime[i] + waterDuration[i]; // When the current slide stops
            int temp = INT_MAX;
            for(int j=0; j<n; j++){
                int start = landStartTime[j];
                int end = landStartTime[j] + landDuration[j];
                if (start > first_end){
                    // The total time will end
                    temp = min(temp, end);
                } else if (start == first_end){
                    temp = min(temp, first_end + landDuration[j]);
                } else {
                    temp = min(temp, first_end + landDuration[j]);
                }
            }
            ans = min(temp, ans);
        }

        return ans;
    }
};