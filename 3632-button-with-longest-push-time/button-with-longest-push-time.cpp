class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int min_diff = events[0][1];
        int k = events[0][0];
        for(int i=1; i<events.size(); i+=1){
            int key = events[i][0];
            int time = events[i][1];
            
            if (time - events[i-1][1] > min_diff){
                min_diff = time-events[i-1][1];
                k = key;
            } else if (time - events[i-1][1] == min_diff){
                k = min(k, key);
            }

        }


        return k;
    }
};