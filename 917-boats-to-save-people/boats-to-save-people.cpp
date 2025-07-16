class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i = 0, j = people.size()-1;
        int boats = 0;
        while (i <= j){
            int weight = people[i] + people[j];
            if (weight > limit){
                j-=1;
            } else {
                i+=1;
                j-=1;
            }
            boats+=1;
        }
        return boats;
    }
};