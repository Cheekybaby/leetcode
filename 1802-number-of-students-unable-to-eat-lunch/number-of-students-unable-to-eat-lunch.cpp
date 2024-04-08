class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int square = 0, triangle = 0;
        for (int i=0; i<students.size(); i+=1){
            if (students[i] == 1){
                square+=1;
            } else {
                triangle+=1;
            }
        }

        for (int i=0; i<sandwiches.size(); i+=1){
            if (sandwiches[i] == 1){
                if (square > 0){
                    square-=1;
                } else {
                    break;
                }
            } else {
                if (triangle > 0){
                    triangle-=1;
                } else {
                    break;
                }
            }
        }

        return square+triangle;
    }
};