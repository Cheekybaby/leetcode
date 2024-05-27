class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        sort(people.begin(), people.end());
        int i=0, j=people.size()-1;
        while (i<=j){
            int sum = people[i] + people[j];
            if (sum > limit){
                j-=1;
            } else if (sum <= limit){
                i+=1;
                j-=1;
            }
            boats+=1;
        }

        return boats;
    }
};