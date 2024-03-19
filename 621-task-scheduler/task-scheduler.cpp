class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for (auto task:tasks){
            freq[task-'A']+=1;
        }

        sort(freq.begin(), freq.end());
        int chunk = freq[25]-1;
        int idle = chunk*n;
        for (int i=24; i>=0;  i-=1){
            idle = idle - min(chunk, freq[i]);
        }

        if (idle < 0){
            return tasks.size();
        }
        return tasks.size() + idle;
    }
};