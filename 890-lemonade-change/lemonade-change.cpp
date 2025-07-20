class Solution {
public:
    bool lemonadeChange(vector<int>& billss) {
        unordered_map<int,int> bills;
        for(int i=0; i<billss.size(); i++){
            int bill = billss[i];
            if (bill == 5){
                bills[bill]++;
            } else if (bill == 10){
                bills[bill]++;
                if (bills[5] > 0){
                    bills[5]--;
                } else {
                    return false;
                }
            } else {
                bills[bill]++;
                if (bills[10] > 0 && bills[5] > 0){
                    bills[10]--;
                    bills[5]--;
                } else if (bills[10] == 0 && bills[5] >= 3){
                    bills[5]-=3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};