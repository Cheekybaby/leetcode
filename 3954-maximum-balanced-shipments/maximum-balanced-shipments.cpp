class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int i=0, cnt = 0;
        while(i < weight.size()){
            priority_queue<int> pq;
            int j = i;
            while (j < weight.size()){
                if (pq.empty()){
                    pq.push(weight[j]);
                    j++;
                    continue;
                }

                if (pq.top() > weight[j]){
                    cnt += 1;
                    i = j+1;
                    break;
                }
                pq.push(weight[j]);
                j++;
            }
            if (j == weight.size()) break;
        }
        return cnt;
    }
};