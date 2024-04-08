class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q_student;
        stack<int> st_sandwich;
        for (int i=0; i<students.size(); i+=1){
            q_student.push(students[i]);
        }
        for (int i=sandwiches.size()-1; i>=0; i-=1){
            st_sandwich.push(sandwiches[i]);
        }
        int count = 0;
        while (!q_student.empty() && count < q_student.size()){
            if (q_student.front() == st_sandwich.top()){
                q_student.pop();
                st_sandwich.pop();
                count = 0;
            } else {
                q_student.push(q_student.front());
                q_student.pop();
                count+=1;
            }
        }

        return q_student.size();
    }
};