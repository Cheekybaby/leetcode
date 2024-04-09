class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        for (int i=0; i<tickets.size(); i+=1){
            if (i<=k){
                time+=min(tickets[i], tickets[k]);
            } else {
                time+=min(tickets[i], tickets[k]-1);
            }
        }

        return time;
    }
};