class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int,double>> time;
        int i=0;
        while (i<size){
            double t = (double)(target - position[i])/speed[i];
            time.push_back({position[i], t});
            i+=1;
        }

        sort(time.begin(), time.end());

        double maxTime = 0;
        int ans = 0;

        for(int i=size-1; i>=0; i-=1){
            double t = time[i].second;
            if (t>maxTime){
                maxTime = t;
                ans+=1;
            }
        }

        return ans;
    }
};